import java.io._
import scala.collection.mutable.ArrayBuffer
import scala.math

object Solution {
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val Array(n, m) = rd.readLine().split(' ').map(_.toInt)
		val t = n * m
		var ans: Double = 0.0
		for (i <- 1 until t + 1) {
			ans += 1.0 / i
		}
		printf("%.7f", ans * t)
	}
}