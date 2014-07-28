import java.io._
import scala.math
import scala.util.Random

object Solution {
	val maxn: Int = 4000000
	var p = new Array[Int](maxn)
	var wt = new Array[Int](maxn)
	var son = Array.ofDim[Int](maxn, 2)
	var size = new Array[Int](maxn)
	var root = new Array[Int](100005)
	var ans = new Array[Int](100005)
	var nn = new Array[Int](100005)
	var pt:Int = 0
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val T = rd.readLine().toInt
		val rand = new Random()
		var flag = false
		for (i <- 1 until T + 1) {
			nn(i) = rd.readLine().toInt
			if (nn(i) < 1) flag = true
		}
		if (!flag) {
			for (i <- 1 until T + 1) {
				val n = nn(i)
				val t = split2(root(i - 1), find(root(i - 1), n))
				pt += 1
				p(pt) = n
				wt(pt) = rand.nextInt()
				if (size(t._1) <= size(t._2)){
					son(pt)(0) = t._1
					size(pt) = size(t._1) + 1
					root(i) = merge2(pt, t._2)
				} else {
					son(pt)(1) = t._2
					size(pt) = size(t._2) + 1
					root(i) = merge2(t._1, pt)
				}
				println(median(root(i)))
			}
			return 
		}
		for (i <- 1 until T + 1) {
            //val n = rand.nextInt(1000000000) % 1000000000 + 1
            //val n = i
            //    println(n)
            val n = nn(i)
			if (n >= 1) {
				val tmp = find(root(i - 1), n)
				val t = split(root(i - 1), tmp)                    
				pt += 1
				p(pt) = n
				wt(pt) = rand.nextInt() 
				if (size(t._1) <= size(t._2)){
					son(pt)(0) = t._1
					size(pt) = size(t._1) + 1
					root(i) = merge(pt, t._2)
				} else {
					son(pt)(1) = t._2
					size(pt) = size(t._2) + 1
					root(i) = merge(t._1, pt)
				}
				ans(i) = median(root(i))
			} else {
				root(i) = root(i + n)
				ans(i) = ans(i + n)
			}
			println(ans(i))
		}
	}
	def find(x: Int, k: Int): Int = {
		if (x == 0) return 0
		if (p(x) == k) return size(son(x)(0))
		if (p(x) > k) return find(son(x)(0), k)
		size(x) - size(son(x)(1)) + find(son(x)(1), k)
	}
	def kth(x: Int, k: Int): Int = {
		if (x == 0) return 0
		val num = size(son(x)(0)) + 1
		if (num == k) return p(x)
		if (num > k) return kth(son(x)(0), k)
		kth(son(x)(1), k - num)
	}
	def median(a: Int): Int = {
		val k = if (size(a) % 2 == 1) (size(a) / 2 + 1) else (size(a) / 2)
		kth(a, k)
	}
	def update(x: Int) {
		size(x) = size(son(x)(0)) + size(son(x)(1)) + 1
	}
	def merge(a: Int, b: Int): Int = {
		if (a == 0) return b
		if (b == 0) return a
		pt += 1
		val now = pt
		if (wt(a) < wt(b)) {
			son(now)(0) = son(a)(0)
			son(now)(1) = merge(son(a)(1), b)
			p(now) = p(a)
			wt(now) = wt(a)
		} else {
			son(now)(0) = merge(a, son(b)(0))
			son(now)(1) = son(b)(1)
			p(now) = p(b)
			wt(now) = wt(b)
		}
		update(now)
		return now
	}
	def split(x: Int, k: Int): Tuple2[Int, Int] = {
		if (x == 0) return (0, 0)
		if (k == 0) return (0, x)
		if (k == size(x)) return (x, 0)
		val num = size(son(x)(0)) + 1
		if (num > k) {
			val t = split(son(x)(0), k)
			if (t._2 == son(x)(0)) {
				return (0, x)
			} else {
				pt += 1
				val now = pt
				p(now) = p(x)
				wt(now) = wt(x)
				son(now)(0) = t._2
				son(now)(1) = son(x)(1)
				update(now)
				return (t._1, now)
			}
		} else {
			val t = split(son(x)(1), k - num)
			if (t._1 == son(x)(1)) {
				return (x, 0)
			} else {
				pt += 1
				val now = pt
				p(now) = p(x)
				wt(now) = wt(x)
				son(now)(0) = son(x)(0)
				son(now)(1) = t._1
				update(now)
				return (now, t._2)
			}
		}
	}
	def merge2(a: Int, b: Int): Int = {
		if (a == 0) return b
		if (b == 0) return a
		if (wt(a) < wt(b)) {
			son(a)(1) = merge2(son(a)(1), b)
			update(a)
			return a
		} else {
			son(b)(0) = merge2(a, son(b)(0))
			update(b)
			return b
		}
	}
	def split2(x: Int, k: Int): Tuple2[Int, Int] = {
		if (x == 0) return (0, 0)
		if (k == 0) return (0, x)
		if (k == size(x)) return (x, 0)
		val num = size(son(x)(0)) + 1
		if (num > k) {
			val t = split2(son(x)(0), k)
			son(x)(0) = t._2
			update(x)
			return (t._1, x)
		} else {
			val t = split2(son(x)(1), k - num)
			son(x)(1) = t._1
			update(x)
			return (x, t._2)
		}
	}
	def output(x: Int) {
		if (son(x)(0) != 0) output(son(x)(0))
		print("(" + x + "," + p(x) + ") ")
		if (son(x)(1) != 0) output(son(x)(1))
	}
}