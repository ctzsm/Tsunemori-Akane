import java.io._
import scala.collection.immutable.TreeSet

object Solution {
	def getMedian(ts: TreeSet[Long]): Long = ts.slice((ts.size - 1) >> 1, ((ts.size - 1) >> 1) + 1).head
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		val fac = 1000000L
		(1 to T).foldLeft(IndexedSeq(new TreeSet[Long]())) { (ls, i) => 
			val n = rd.readLine().toInt
			val set = if (n >= 0) {
				ls.last + (fac * n + i)
			} else {
				ls(ls.length + n)
			}
			println(getMedian(set) / fac)
			ls :+ set
		}
	}
}