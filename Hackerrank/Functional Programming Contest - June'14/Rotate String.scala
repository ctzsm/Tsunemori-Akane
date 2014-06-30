import java.io._
import scala.collection.mutable
import scala.math

object Solution {
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		for (i <- 0 until T) {
			var s = rd.readLine()
			val n = s.length()
			for (j <- 0 until n - 1) {
				s = s.slice(1, n) + s.slice(0, 1)
				print(s + ' ')
			}
			s = s.slice(1, n) + s.slice(0, 1)
			println(s)
		}
	}
}