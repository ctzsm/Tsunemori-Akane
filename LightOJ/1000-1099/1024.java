import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int T = in.nextInt();
		for (int _ = 1; _ <= T; ++_) {
			int n = in.nextInt();
			BigInteger ans = BigInteger.ONE;
			for (int i = 0; i < n; ++i) {
				BigInteger x = in.nextBigInteger();
				ans = ans.multiply(x).divide(ans.gcd(x));
			}
			System.out.println("Case " + _ + ": " + ans);
			System.gc();
		}
	}
}
