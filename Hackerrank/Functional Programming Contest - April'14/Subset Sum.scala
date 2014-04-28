import java.io._
import scala.collection.mutable
import scala.math
import BigInt._

object Solution {
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val n = rd.readLine().toInt
		val a = rd.readLine().split(' ').map(BigInt(_)).sortWith(_ > _).scanLeft(BigInt(0))(_ + _)		
		val t = rd.readLine().toInt
		for(i <- 0 until t) {
			val s = BigInt(rd.readLine())
			if (s > a(a.length-1)) {
				println(-1)
			} else {
                var l = 0
		        var r = a.length - 1
				while(l < r) {
					var mid = (l + r) / 2
					if (a(mid) >= s) {
						r = mid
					} else {
						l = mid + 1
					}
				}
				println(l)
			}
		}
	}
}