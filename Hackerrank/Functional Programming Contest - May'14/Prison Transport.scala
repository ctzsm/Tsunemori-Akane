import java.io._
import scala.math
import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.HashMap

object Solution {
	var father = ArrayBuffer[Int]()
	var rank = ArrayBuffer[Int]()
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val N = rd.readLine().toInt
		val M = rd.readLine().toInt
		for (i <- 0 until N) {
			father.append(i) 
			rank.append(1)
		}
		for (i <- 0 until M) {
			val Array(u, v) = rd.readLine().split(' ').map(_.toInt)
			union(u - 1, v - 1)
		}
		var answer = 0
		for (i <- 0 until N) {
			if (father(i) == i) {
				answer += calc(rank(i))
			}
		}
		println(answer)
	}
	def find(x: Int) : Int = {
		if (father(x) != x) {
			father(x) = find(father(x))
		}
		return father(x)
	}
	def union(x: Int, y: Int) {
		val fx = find(x)
		val fy = find(y)
		if (fx == fy) return
		if (rank(fx) < rank(fy)) {
			father(fx) = fy
			rank(fy) += rank(fx)
		} else {
				father(fy) = fx
				rank(fx) += rank(fy)
		}
	}
	def calc(x: Int) : Int = {
		for (i <- 0 until 318) {
			if (x <= i * i) return i
		}
		return 0
	}
}