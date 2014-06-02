import java.io._
import scala.collection.mutable
import scala.math

object Solution {
	var memo = mutable.ArrayBuffer.fill(301)(-1)
	def main(args: Array[String]) {
		memo(0) = 0
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		for (i <- 0 until T) {
			val N = rd.readLine().toInt
			val a = rd.readLine().split('X').map(_.length)
			var res = 0
			for (x <- a) {
				res ^= dfs(x)
			}
			if (res == 0) {
				println("LOSE")
			} else {
				println("WIN")
			}
		}
	}
	def dfs(x : Int) : Int = {
		if (memo(x) != -1) {
			return memo(x)
		}
		var v = mutable.ArrayBuffer.fill(100)(false)
		for (i <- 0 until x) {
			v(dfs(i) ^ dfs(x - i - 1)) = true
		}
		for (i <- 0 until (x - 1)) {
			v(dfs(i) ^ dfs(x - i - 2)) = true
		}
		for (i <- 0 until v.length) {
			if (!v(i)) {
				memo(x) = i
				return memo(x)
			}
		}
		return -1
	}
}