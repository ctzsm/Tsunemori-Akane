import java.io._
import scala.collection.mutable
import scala.math

object Solution {
	var memo = mutable.ArrayBuffer.fill(62, 62, 7)(-1)
	var righ = Array(2, 3, 1, 0, 4, 5)
	var down = Array(5, 4, 2, 3, 0, 1)
	def main(args: Array[String]) {
		var dice = mutable.ArrayBuffer.fill(3, 6)(-1)
		memo(1)(1)(0) = 1
		memo(1)(1)(1) = 6
		memo(1)(1)(2) = 3
		memo(1)(1)(3) = 4
		memo(1)(1)(4) = 2
		memo(1)(1)(5) = 5
		memo(1)(1)(6) = memo(1)(1)(0)
		for (i <- 2 until 61) {
			for (k <- 0 until 6) {
				memo(i)(1)(k) = memo(i - 1)(1)(down(k))
				memo(1)(i)(k) = memo(1)(i - 1)(righ(k))
			}
			memo(i)(1)(6) = memo(i)(1)(0) + memo(i - 1)(1)(6)
			memo(1)(i)(6) = memo(1)(i)(0) + memo(1)(i - 1)(6)
		}
		for (i <- 1 until 60) {
			for (j <- 1 until 60) {
				for (len <- 1 until 9) {
					for (mask <- 0 until (1 << len)) {
						for (k <- 0 until 6) {
							dice(0)(k) = memo(i)(j)(k)
						}
						var (r, d) = Pair(j, i)
						var (now, nxt) = Pair(0, 1)
						var sum = 0
						for (k <- 0 until len) {
							if ((mask & (1 << k)) > 0) { // 1 for right, 0 for down
								r += 1
								for (l <- 0 until 6) {
									dice(nxt)(l) = dice(now)(righ(l))
								}
							} else {
								d += 1
								for (l <- 0 until 6) {
									dice(nxt)(l) = dice(now)(down(l))
								}
							}
							sum += dice(nxt)(0)
							now ^= 1
							nxt ^= 1
						}
						if (d <= 60 && r <= 60 && sum + memo(i)(j)(6) > memo(d)(r)(6)) {
							for (k <- 0 until 6) {
								memo(d)(r)(k) = dice(now)(k)
							}
							memo(d)(r)(6) = sum + memo(i)(j)(6)
						}
					}
				}
			}
		}
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		for (i <- 0 until T) {
			val Array(n, m) = rd.readLine().split(' ').map(_.toInt)
			println(memo(n)(m)(6))
		}
	}
}