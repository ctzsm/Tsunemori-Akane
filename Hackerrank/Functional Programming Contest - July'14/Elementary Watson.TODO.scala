import java.io._
import scala.math
import scala.util.parsing.combinator._
import scala.collection.mutable.Map

object Solution extends JavaTokenParsers {
	sealed trait Expr {
		val const = false
	}
	case class Name(s: String) extends Expr {
		override def toString(): String = s
		override val const = true
	}
	case class Variable(s: String) extends Expr {
		override def toString(): String = s
	}
	case class Relation(name: Name, list: List[Expr]) extends Expr {
		// "[" <name> ": " <simple-term> <simple-terms> "]"
		override def toString(): String = "[" + name.toString() + ": " + list.mkString(", ") + "]"
		override val const = list.foldLeft(true)((r, e) => (r && e.const))
	}
	case class Equality(a: Expr, b: Expr) extends Expr {
		override val const = a.const && b.const
	}
	case class NonEquality(a: Expr, b: Expr) extends Expr {
		override val const = a.const && b.const
	}
	case class Rule(a: Expr, list: List[Expr]) extends Expr {
		override val const = a.const && list.foldLeft(true)((r, e) => (r && e.const))
		println("Ok.")
		a match {
			case r: Relation => if (list.isEmpty && r.const) { 
				val key = r.name.toString() + r.list.length
				stream1.update(key, stream1.getOrElse(key, List[List[Expr]]()) :+ r.list)
			}
			case _ =>
		}
		stream2 = stream2 :+ this
	}
	case class Query(list: List[Expr]) extends Expr {
		flag = true
		val res = unifyTerms(list, stream2, Map())
		if (!flag) {
			println("UNSAT")
		}
		println("Ready.")
	}
	lazy val name: Parser[Name] = """[a-zA-Z][a-zA-Z0-9\-]*""".r ^^ (x => new Name(x))
	lazy val variable: Parser[Variable] = """#[a-zA-Z][a-zA-Z0-9\-]*""".r ^^ (x => new Variable(x))
	lazy val relational_term: Parser[Relation] = "[" ~ name ~ ": " ~ simple_terms ~ "]" ^^ { case _ ~ name ~ _ ~ list ~ _ => new Relation(name, list) }
	lazy val simple_term: Parser[Expr] = name | variable | relational_term
	lazy val simple_terms: Parser[List[Expr]] = simple_term ~ rep(", " ~ simple_term) ^^ { case head ~ list => List(head) ++ list.map({ case _ ~ x => x }) }
	lazy val equality_assertion: Parser[Equality] = "<" ~ simple_term ~ "=" ~ simple_term ~ ">" ^^ { case _ ~ a ~ _ ~ b ~ _ => new Equality(a, b) }
	lazy val non_equality_assertion: Parser[NonEquality] = "<" ~ simple_term ~ "/=" ~ simple_term ~ ">" ^^ { case _ ~ a ~ _ ~ b ~ _ => new NonEquality(a, b) }
	lazy val complex_term: Parser[Expr] = simple_term | equality_assertion | non_equality_assertion
	lazy val complex_terms: Parser[List[Expr]] = complex_term ~ rep(", " ~ complex_term) ^^ { case head ~ list => List(head) ++ list.map({ case _ ~ x => x }) }
	lazy val rule: Parser[Rule] = simple_term ~ "." ^^ { case x ~ _ => new Rule(x, List[Expr]()) } | "{(" ~ complex_terms ~ ") => " ~ simple_term ~ "}." ^^ { case _ ~ list ~ _ ~ x ~ _ => new Rule(x, list) }
	lazy val query: Parser[Query] = "(" ~ complex_terms ~ ")?" ^^ { case _ ~ x ~ _ => new Query(x) }
	lazy val op: Parser[Any] = rule | query

	var stream1 = Map[String, List[List[Expr]]]()
	var stream2 = List[Expr]()
	var flag = false;

	def unifyTerms(left: List[Expr], right: List[Expr], env: Map[Variable, Expr]): Option[Map[Variable, Expr]] = {
		(left, right) match {
			case (x :: xtail, y :: ytail) => (x, y) match {
				case (a: Variable, _) => unifyVars(a, y, env)
				case (_, a: Variable) => unifyVars(a, y, env)
				case (Relation(_, xterms), Relation(_, yterms)) => unifyTerms(xterms, yterms, env)
				case _ => {
					flag = false
					None
				}
			}
			case (Nil, Nil) => Some(env)
			case _ => {
				flag = false
				None
			}
		}
	}
	def unifyVars(variable: Variable, x: Expr, env: Map[Variable, Expr]): Option[Map[Variable, Expr]] = {
		(env get variable, x) match {
			case (Some(value), _) => unifyTerms(List(value), List(x), env)
			case (None, xVar: Variable) if env contains xVar => unifyTerms(List(variable), List(env(xVar)), env)
			case (None, _) => {
				flag = false
				None
			}
		}
	}
	def equal(a: Expr, b: Expr): Boolean = {
		(a, b) match {
			case (a: Name, b: Name) => a.s == b.s
			case (a: Variable, b: Variable) => a.s == b.s
			case (a: Relation, b: Relation) => a.name.s == b.name.s && a.list.length == b.list.length && (a.list zip b.list).foldLeft(true)((r, e) => r && equal(e._1, e._2))
			case (_, _) => false
		}
	}
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		var s = rd.readLine()
		while (s != null) {
			if (s == "quit!") return
			if (s != "" && !s.startsWith("%")) {
				println(parseAll(op, s))
			}
			s = rd.readLine()
		}
	}
}