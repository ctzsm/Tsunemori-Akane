import java.io._
import scala.collection.mutable.ArrayBuffer
import scala.math

object Solution {
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val Array(m, n, r) = rd.readLine().split(' ').map(_.toInt)
		var mat: ArrayBuffer[ArrayBuffer[Int]] = new ArrayBuffer[ArrayBuffer[Int]]
		for (i <- 0 until m) {
			mat += rd.readLine().split(' ').map(_.toInt).to[ArrayBuffer]
		}
		var lm = m
		var ln = n
		for (i <- 0 until math.min(n, m) / 2) {
			var len = lm * 2 + ln * 2 - 4
			var now: ArrayBuffer[Int] = new ArrayBuffer[Int]
			for (j <- 0 until ln - 1) now += mat(i)(i+j)
			for (j <- 0 until lm - 1) now += mat(i+j)(i+ln-1)
			for (j <- 0 until ln - 1) now += mat(i+lm-1)(i+ln-j-1)
			for (j <- 0 until lm - 1) now += mat(i+lm-j-1)(i)
			for (j <- 0 until len) now += now(j)
			var idx = r % len
			for (j <- 0 until ln - 1) mat(i)(i+j) = now(idx+j)
			idx += ln - 1
			for (j <- 0 until lm - 1) mat(i+j)(i+ln-1) = now(idx+j)
			idx += lm - 1
			for (j <- 0 until ln - 1) mat(i+lm-1)(i+ln-j-1) = now(idx+j)
			idx += ln - 1
			for (j <- 0 until lm - 1) mat(i+lm-j-1)(i) = now(idx+j)
			//println(now)
			lm -= 2
			ln -= 2
		}
		for (i <- 0 until m) {
			for (j <- 0 until n - 1) {
				print(mat(i)(j) + " ")
			}
			println(mat(i)(n-1))
		}
	}
}