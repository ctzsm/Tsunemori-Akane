import java.io._
import scala.collection.mutable
import scala.math

case class Node(
	val a: Long,
	val h: Long)
object Solution {
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val Array(n, m) = rd.readLine().split(' ').map(_.toLong)
		val a = rd.readLine().split(' ').map(_.toLong)
		val h = rd.readLine().split(' ').map(_.toLong)
		var f: mutable.ArrayBuffer[Node] = mutable.ArrayBuffer[Node]()
		for (i <- 0 until n.toInt) {
			f.append(Node(a(i), h(i)))
		}
		var s: Long = 0
		for (j <- 0 until n.toInt) {
			s += f(j).a + (n - 1) * f(j).h
		}
		if (s <= m) {
			println(n)
			return
		}
		var l: Int = 0
		var r: Int = n.toInt
		var mid: Int = 0
		while (l < r) {
			mid = (l + r) / 2
			f = f.sortBy(x => x.a + (mid - 1) * x.h)
			s = 0
			for (j <- 0 until mid) {
				s += f(j).a + (mid - 1) * f(j).h
			}
			if (s > m) r = mid
			else l = mid + 1
		}
		println(l - 1)
	}
}