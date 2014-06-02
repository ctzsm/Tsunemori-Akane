import java.io._
import scala.collection.mutable.Stack
import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.StringBuilder

abstract class AE {
	def T(): AE = this
	def free(atom: Atom): Boolean = false
	def is(atom: Atom): Boolean = false
	def output():String = ""
}
case class Atom(symbol: String) extends AE {
	override def free(atom: Atom): Boolean = symbol == atom.symbol
	override def is(atom: Atom): Boolean = free(atom)
	override def output():String = {
		if (symbol(0) == '['){
			symbol.substring(1)
		} else {
			symbol
		}
	}
}
case class Expr(left: AE, right: AE) extends AE {
	override def T(): AE = new Expr(left.T(), right.T())
	override def free(atom: Atom): Boolean = left.free(atom) || right.free(atom)
	override def output(): String = {
		right match{
			case right:Atom => left.output() + right.output()
			case _ => left.output() + "(" + right.output() + ")"
		}    
	}
}
case class Lambda(variable: Atom, expr: AE) extends AE {
	override def T(): AE = {
		expr match{
			case expr:Expr => {
				if(!expr.left.free(variable) && expr.right.is(variable)) {
					return expr.left.T()
				} else if (expr.left.free(variable) && !expr.right.free(variable)){
					return new Expr(new Expr(new Atom("[C"), (new Lambda(variable, expr.left)).T()), expr.right.T())
				} else if (!expr.left.free(variable) && expr.right.free(variable)){
					return new Expr(new Expr(new Atom("[B"), expr.left.T()), (new Lambda(variable, expr.right)).T())
				} else if(expr.left.free(variable) && expr.right.free(variable)) {
					return new Expr(new Expr(new Atom("[S"), (new Lambda(variable, expr.left)).T()), (new Lambda(variable, expr.right)).T())
				} else {
					return new Expr(new Atom("[K"), expr.T())
				}
			}
			case atom:Atom => {
				if(atom.is(variable)){
					return new Atom("[I")
				} else {
					return new Expr(new Atom("[K"), atom)
				}
			}
			case lamb:Lambda => {
				if (lamb.expr.free(variable)) {
					return (new Lambda(variable, lamb.T())).T()
				} else {
					return new Expr(new Atom("[K"), lamb.T())
				}
			}
		}
	}
	override def free(atom: Atom): Boolean = !variable.is(atom) && expr.free(atom)
	override def output(): String = "(\\" + variable.output() + ". " + expr.output() + ")"
}
object Solution {
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in), 131072)
		val T = rd.readLine().toInt
		var exp = rd.readLine()
		while(exp != null) {
			val par = parse(exp).T()
			println(par.output())
			exp = rd.readLine()
		}        
	}
	def parse(str: String): AE = {
		var stack: Stack[Int] = Stack()
		var pidx: ArrayBuffer[Int] = ArrayBuffer.fill(str.length)(-1)
		for (i <- 0 until str.length) {
			if (str(i) == '(') {
				stack.push(i)
			} else if (str(i) == ')') {
				val id = stack.pop()
				pidx(id) = i
				pidx(i) = id
			}
		}
		parseExpr(str, pidx, 0, pidx(0))
	}
	def joinExpr(left: AE, right: AE): AE = {
		if (left == null) {
			right
		} else {
			new Expr(left, right)
		}
	}
	def parseExpr(str: String, pidx: ArrayBuffer[Int], ll: Int, rr: Int): AE = {
		var l = ll
		var r = rr
		while (Character.isWhitespace(str(l))) l = l + 1
		while (Character.isWhitespace(str(r))) r = r - 1
		if (str(l) == '(' && pidx(l) == r) {
			parseExpr(str, pidx, l + 1, r - 1)
		} else if (str(l) == '\\') {
			val idx = str.indexOf('.', l + 1)
			val variables = str.substring(l + 1, idx).split(Array(' ', '\t', '\r', '\n'))
			parseLambda(variables, parseExpr(str, pidx, idx + 1, r), 0)
		} else {
			var a: AE = null
			var i = l
			while (i <= r) {
				if (!Character.isWhitespace(str(i))) {
					if (str(i) == '(') {
						a = joinExpr(a, parseExpr(str, pidx, i, pidx(i)))
						i = pidx(i) + 1
					} else if(str(i) == '\\'){
						a = joinExpr(a, parseExpr(str, pidx, i, r))
						i = r + 1
					} else {
						var idx = str.indexWhere(c => Character.isWhitespace(c) || c == '(' || c == ')', i)
						if (idx > r || idx == -1) {
							idx = r + 1    
						}
						a = joinExpr(a, new Atom(str.substring(i, idx)))
						i = idx
					}
				} else {
					i += 1
				}
			}
			a
		}
	}
	def parseLambda(variables: Array[String], interm: AE, depth: Int): AE = {
		if (depth == variables.length - 1) {
			new Lambda(new Atom(variables(depth)), interm)
		} else {
			new Lambda(new Atom(variables(depth)), parseLambda(variables, interm, depth + 1))
		}
	}
}