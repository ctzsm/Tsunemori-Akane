import java.io._
import scala.collection.mutable
import scala.math

object Solution {
	val maxn: Int = 30005
	var od: mutable.ArrayBuffer[Int] = new mutable.ArrayBuffer[Int]()
	var a = mutable.ArrayBuffer.fill(maxn)(0)
	var tree = mutable.ArrayBuffer.fill(20, maxn)(0)
	var ld = mutable.ArrayBuffer.fill(20, maxn)(0)
	var lv = mutable.ArrayBuffer.fill(maxn)(0)
	var rv = mutable.ArrayBuffer.fill(maxn)(0)
	var adj = mutable.ArrayBuffer.fill(maxn)(new mutable.ArrayBuffer[Int])
	var salary: Array[Int] = null
	var id: mutable.ArrayBuffer[Int] = new mutable.ArrayBuffer[Int]()
	var ssalary = mutable.ArrayBuffer.fill(maxn)(0)
	var n: Int = 0
	var idx: Int = 1
	def main(args: Array[String]) {
		val rd = new BufferedReader(new InputStreamReader(System.in))
		val Array(_n, _q) = rd.readLine().split(' ').map(_.toInt)
		for (i <- 1 until _n) {
			val Array(u, p) = rd.readLine().split(' ').map(_.toInt)
			adj(p) += u
		}
		salary = rd.readLine().split(' ').map(_.toInt)
		id += 0
		dfs(1)
		init(_n, ssalary)
		var _v = 0
		for (i <- 0 until _q) {
			var Array(v, k) = rd.readLine().split(' ').map(_.toInt)
			v += _v
			_v = query(lv(v), rv(v) - 1, k)
			println(_v)
		}
	}
	def dfs(u: Int) {
		ssalary(idx) = salary(u - 1)
		id += u
		idx += 1
		lv(u) = idx
		for (v <- adj(u)) {
			dfs(v)
		}
		rv(u) = idx
	}
	def build(l: Int, r: Int, d: Int) {
		if (l == r) return
		var mid: Int = (l + r) >> 1
		var p: Int = 0
		for (i <- l until r + 1) {
			if (tree(d)(i) <= mid) {
				tree(d + 1)(l + p) = tree(d)(i)
				p += 1
				ld(d)(i) = p
			} else {
				tree(d + 1)(mid + i - l + 1 - p) = tree(d)(i)
				ld(d)(i) = p
			}
		}
		build(l, mid, d + 1)
		build(mid + 1, r, d + 1)
	}
	def query(s: Int, e: Int, k: Int, l: Int = 1, r: Int = n, d: Int = 0): Int = {
		if (l == r) return id(od(l))
		var ss: Int = 0
		if (s > l)
			ss = ld(d)(s - 1)
		var ee: Int = ld(d)(e)
		var mid: Int = (l + r) >> 1
		if (ee - ss >= k) {
			query(l + ss, l + ee - 1, k, l, mid, d + 1)
		} else {
			query(mid + 1 + (s - l - ss), mid + 1 + (e - l - ee), k - (ee - ss), mid + 1, r, d + 1)
		}
	}
	def init(_n: Int, num: mutable.ArrayBuffer[Int]) = {
		n = _n
		od += 0
		for (i <- 1 until n + 1) {
			a(i) = num(i)
			od += i
		}
		od = od.sortBy(elem => num(elem))
		for (i <- 1 until n + 1) {
			tree(0)(od(i)) = i
		}
		build(1, n, 0)
	}
}