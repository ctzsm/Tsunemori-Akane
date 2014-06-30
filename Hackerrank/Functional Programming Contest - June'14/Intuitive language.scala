import java.io._
import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap
import scala.math
import scala.util.parsing.combinator._
import scala.annotation.tailrec

class Fraction(var n: Long, var d: Long) {
	private val g = gcd(math.abs(n), math.abs(d))
	private val s = sign(n) * sign(d)
	n = math.abs(n) / g * s
	d = math.abs(d) / g
	@tailrec private def gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)
	private def sign(a: Long): Long = if (a < 0) -1 else if (a > 0) 1 else 0
	override def toString = if (d == 1 || n == 0) n + "" else n + "/" + d
	def +(b: Fraction) = new Fraction(n * b.d + d * b.n, d * b.d)
	def -(b: Fraction) = new Fraction(n * b.d - d * b.n, d * b.d)
	def *(b: Fraction) = new Fraction(n * b.n, d * b.d)
	def /(b: Fraction) = new Fraction(n * b.d, d * b.n)
}
case class Func(var co: ArrayBuffer[Fraction]) {
	def eval(pa: ArrayBuffer[Fraction]) {
		var res = new Fraction(0, 1)
		for (i <- 0 until pa.length) {
			res += pa(i) * co(i)
		}
		for (i <- pa.length until co.length - 1) {
			print(co(i) + ", ")
		}
		println((res + co(co.length - 1)))
	}
	def getValue(pa: ArrayBuffer[Fraction]): Fraction = {
		var res = new Fraction(0, 1)
		for (i <- 0 until pa.length) {
			res += pa(i) * co(i)
		}
		res + co(co.length - 1)
	}
}

object Solution extends JavaTokenParsers with PackratParsers {
	sealed trait Expr {
		def eval(): Fraction = null
	}
	case class BinOpExpr(op: String, left: Expr, right: Expr) extends Expr {
		override def eval(): Fraction = op match {
			case "+" => left.eval() + right.eval()
			case "-" => left.eval() - right.eval()
			case "*" => left.eval() * right.eval()
			case "/" => left.eval() / right.eval()
		}
	}
    case class NumExpr(num: Fraction) extends Expr {
        override def eval() = num
    }
	case class Fvalue(n: String, coe: ArrayBuffer[Expr]) extends Expr {
		override def eval() = {
			var ops = new ArrayBuffer[Fraction]
			for (e <- coe) {
				ops += e.eval
			}
			if (functions(n).co.length - 1 == ops.length) {
				functions(n).getValue(ops)
			} else {
				functions(n).eval(ops)
				new Fraction(1, 0)
			}
		}
	}
	lazy val expr: PackratParser[Expr] =
		(expr ~ addop ~ term ^^ { case e ~ op ~ t => BinOpExpr(op, e, t) }
			| term)
	lazy val term: PackratParser[Expr] =
		(term ~ mulop ~ factor ^^ { case t ~ op ~ f => BinOpExpr(op, t, f) }
			| factor)
	lazy val factor: PackratParser[Expr] =
		(variable
			| "(" ~ expr ~ ")" ^^ { case _ ~ e ~ _ => e }
			| wholeNumber ^^ { case numLit => NumExpr(new Fraction(numLit.toLong, 1)) })
	lazy val addop: PackratParser[String] = "+" | "-"
	lazy val mulop: PackratParser[String] = "*" | "/"
	lazy val variable: PackratParser[Expr] = """[a-z]+[0-9]*""".r ~ rep("[" ~> expr <~ "]") ^^ {
		case n ~ ops => Fvalue(n, ops.to[ArrayBuffer])
	}

	var functions: HashMap[String, Func] = new HashMap[String, Func]()
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		var s = rd.readLine()
		// println(parseAll(expr, "sum[1+1][1]"))
		var text = ""
		while (s != null) {
			text += s.trim
			s = rd.readLine()
		}
		var lines = text.toLowerCase().split(Array('.', '?', '!'))
		for (line <- lines) {
			if (line.startsWith("what ")) {
				query(line)
			} else if (line.startsWith("assign ")) {
				assign(line, 1)
			} else if (line.startsWith("do ")) {
				doloop(line)
			} else {
				declare(line)
			}
		}
	}
	def query(s: String) {
		var ss = s.stripPrefix("what").trim.stripPrefix("is").trim.split(" and ").map(_.trim)
		for (v <- ss) {
			var r = parseAll(expr, v).get.eval
			if (r.d != 0) {
				println(r)
			}
		}
	}
	def assign(s: String, t: Int) {
		var ss = s.stripPrefix("assign ").split(" and ").map(_.trim.split(" to ").map(_.trim))
		var res = new ArrayBuffer[Expr]()
		for (par <- ss) {
			if (!functions.contains(par(1))) {
				var co = new ArrayBuffer[Fraction]()
				var result = parseAll(expr, par(0)).get
				res += result
				co += result.eval()
				functions(par(1)) = new Func(co)
			} else {                
				var result = parseAll(expr, par(0)).get
				res += result
				functions(par(1)).co(0) = result.eval()
			}
		}
		for (i <- 1 until t) {
			for (j <- 0 until ss.length) {
				functions(ss(j)(1)).co(0) = res(j).eval()
			}
		}
	}
	def doloop(s: String) {
		var idx = s.indexOf('{')
		var idp = s.indexOf('}')
		var up = parseAll(expr, s.substring(idx + 1, idp).trim).get.eval().n.toInt
		var ass = s.substring(idp + 1, s.length).trim
		assign(ass, up)
	}
	def declare(s: String) {
		var co = new ArrayBuffer[Fraction]()
		var idx = s.indexOf(' ')
		val name = s.substring(0, idx).trim
		if (s.containsSlice(" function ")) {
			idx = s.indexOf(':')
			var ks = s.substring(idx + 1, s.length).split(',').map(_.trim)
			for (k <- ks) {
				co += parseAll(expr, k).get.eval()
			}
		} else {
			var ss = s.substring(idx + 1, s.length).trim.stripPrefix("is").trim
			co += parseAll(expr, ss).get.eval()
		}
		functions(name) = new Func(co)
	}
}