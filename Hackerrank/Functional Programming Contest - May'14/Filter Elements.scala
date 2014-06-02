import java.io._
import scala.collection.mutable
import scala.math

object Solution {
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		for (i <- 0 until T) {
			val Array(n, k) = rd.readLine().split(' ').map(_.toInt)
			val a = rd.readLine().split(' ').map(_.toInt)
			var m = a.clone().groupBy(e => e).mapValues(x=>x.length)
			var flag = true
			for (x <- a) {
				if (m.contains(x)) {
					if (m(x) >= k) {
						print(x + " ")
						m = m - x
						flag = false
					}
				}
			}
			if (flag) {
				println(-1)
			} else {
				println()
			}
		}
	}
}