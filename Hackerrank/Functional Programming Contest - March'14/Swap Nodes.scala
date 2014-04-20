import java.io._
import scala.collection.mutable
import scala.math

case class Node(
  val l: Int,
  val r: Int
)
object Solution {
	val a: mutable.ArrayBuffer[Node] = mutable.ArrayBuffer[Node]()
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val n = rd.readLine().toInt
		for (i <- 0 until n) {
			val Array(l, r) = rd.readLine().split(' ').map(_.toInt)
			a.append(Node(l, r))
		}
		val T = rd.readLine().toInt
		for (i <- 0 until T) {
			val k = rd.readLine().toInt
			tswap(1, k, 1)
			println()
		}
	}
	def tswap(x: Int, k: Int, d: Int) {
		if (x <= 0) return
		val id = x - 1
		val l = a(id).l
		val r = a(id).r
		if (d % k == 0) {
			a(id) = Node(r, l)
		}
		tswap(a(id).l, k, d + 1)
		print(x + " ")
		tswap(a(id).r, k, d + 1)
	}
}