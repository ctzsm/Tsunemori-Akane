import java.io._
import scala.collection.mutable
import scala.math

object Solution {
	var memo = mutable.ArrayBuffer.fill(26, 26, 26)(-1)
	def main(args: Array[String]) {
		memo(1)(0)(0) = 0
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		for (i <- 0 until T) {
			val Array(r1, r2, r3) = rd.readLine().split(' ').map(_.toInt)
			val res = dfs(r1, r2, r3)
			if (res == 0) {
				println("LOSE")
			} else {
				println("WIN")
			}
		}
	}
	def dfs(r1: Int, r2: Int, r3: Int) : Int = {
		if (memo(r1)(r2)(r3) != -1) {
			return memo(r1)(r2)(r3)
		}
		var v = mutable.ArrayBuffer.fill(100)(false)
		for (i <- 1 until r1) {
			v(dfs(i, math.min(i, r2), math.min(i, r3))) = true
		}
		for (i <- 0 until r2) {
			v(dfs(r1, i, math.min(i, r3))) = true
		}
		for (i <- 0 until r3) {
			v(dfs(r1, r2, i)) = true
		}
		for (i <- 0 until v.length) {
			if (!v(i)) {
				memo(r1)(r2)(r3) = i
				return memo(r1)(r2)(r3)
			}
		}
		return -1
	}
}