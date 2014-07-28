import java.io._
import scala.collection.mutable
import scala.math

object Solution {
	var memo = mutable.ArrayBuffer.fill(101, 101, 101, 2)(0) // 0 for right 1 for down
	val mod: Int = 1000000007
	def main(args: Array[String]) {
		for (i <- 1 until 101) {
			for (j <- 1 until 101) {
				if (i == 1 && j == 1) {
				} else if (i == 1 && j == 2) {
					memo(i)(j)(0)(0) = 1
				} else if (i == 2 && j == 1) {
					memo(i)(j)(0)(1) = 1
				} else {
					for (k <- 0 until 101) {
						if (k == 0) {
							memo(i)(j)(k)(0) = memo(i)(j-1)(k)(0)
							memo(i)(j)(k)(1) = memo(i-1)(j)(k)(1)
						} else {							
							memo(i)(j)(k)(0) = (memo(i)(j-1)(k)(0) + memo(i)(j-1)(k-1)(1)) % mod
							memo(i)(j)(k)(1) = (memo(i-1)(j)(k)(1) + memo(i-1)(j)(k-1)(0)) % mod
						}
					}
				}
			}
		}
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		for (i <- 0 until T) {
			val Array(n, m, k) = rd.readLine().split(' ').map(_.toInt)
			if (n == 1 && m == 1) {
				println(1)
			} else {
				var ans: Int = 0
				for (j <- 0 until k + 1) {
					ans = (ans + memo(n)(m)(j)(0)) % mod
					ans = (ans + memo(n)(m)(j)(1)) % mod
				}
				println(ans)
			}
		}
	}
}