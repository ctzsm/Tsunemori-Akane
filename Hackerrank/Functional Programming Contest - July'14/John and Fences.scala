import java.io._
import scala.collection.mutable.ArrayBuffer
import scala.math

object Solution {
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val N = rd.readLine().toInt
		val h = Array(0) ++ rd.readLine().split(' ').map(_.toInt) ++ Array(0)
		var l: ArrayBuffer[Int] = ArrayBuffer.fill(h.length)(-1)
		var r: ArrayBuffer[Int] = ArrayBuffer.fill(h.length)(-1)
		for (i <- 1 until h.length - 1) {
			var ll: Int = i - 1
			if (h(ll) < h(i)) {
				l(i) = i
			} else {
				while (ll != -1 && h(ll) >= h(i)) {
					l(i) = ll
					if (ll == l(ll)) ll = ll - 1
					else ll = l(ll)
				}
			}
		}
		for (i <- h.length - 2 to 1 by -1) {
			var rr: Int = i + 1
			if (h(rr) < h(i)) {
				r(i) = i
			} else {
				while (rr != -1 && h(rr) >= h(i)) {
					r(i) = rr
					if (rr == r(rr)) rr = rr + 1
					else rr = r(rr)
				}
			}
		}
		var ans = 0
		for (i <- 1 until h.length - 1) {
			ans = math.max(ans, (r(i) - l(i) + 1) * h(i))
		}
		println(ans)
	}
}