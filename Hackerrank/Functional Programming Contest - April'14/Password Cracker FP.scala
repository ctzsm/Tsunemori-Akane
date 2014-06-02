import java.io._
import scala.collection.mutable
import scala.math
import BigInt._

object Solution {
	var answer = mutable.ArrayBuffer[Int]()
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		for (i <- 0 until T) {
			val N = rd.readLine().toInt
			val pass = rd.readLine().split(' ').sortBy(_.length)
			val login = rd.readLine()
			answer.clear()
			var flag = true
			for (x <- pass) {
				if (login.endsWith(x)) {
					flag = false
				}
			}
			for (j <- 0 until login.length) {
				var t = false
				for (x <- pass) {
					if (x contains login(j)) {
						t = true
					}
				}
				if (!t) {
					flag = true
				}
			}
			if (flag) {
				println("WRONG PASSWORD")
			} else if (dfs(login, pass, 0)) {
				for (i <- 0 until answer.length - 1) {
					print(pass(answer(i)) + " ")
				}
				println(pass(answer(answer.length - 1)))
			} else {
				println("WRONG PASSWORD")
			}
		}
	}
	def dfs(login: String, pass: Array[String], off: Int): Boolean = {
		for (i <- 0 until pass.length) {
			if (login.length - off == pass(i).length) {
				if (login.endsWith(pass(i))) {
					answer.append(i)
					return true
				}
			} else if (login.length - off < pass(i).length) {
			} else if (login.startsWith(pass(i), off)) {
				answer.append(i)
				if (dfs(login, pass, off + pass(i).length)) {
					return true
				}
				answer.dropRight(1)
			}
		}
		return false
	}
}