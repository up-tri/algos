import java.util.*;

/**
 * D main
 *
 * @date 2020.09.19
 * @author 焼き鮭 <yaki-shake@up-tri.me>
 */

// できてない
public class Main {
  Scanner sc;
  long MOD = 998244353;

  boolean[] pattern;
  long[] memo;

  public static void main(String[] args) {
    new Main().execute();
  }

  public void execute() {
    this.sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();

    this.pattern = new boolean[n + 1];
    this.memo = new long[n + 1];

    for (int i = 0; i <= n; i++) {
      this.memo[i] = -1;
    }

    for (int i = 0; i < k; i++) {
      int start = sc.nextInt();
      int end = sc.nextInt();
      for (int j = start; j <= end; j++) {
        this.pattern[j] = true;
      }
    }

    System.out.println(steps(n));
  }

  public long steps(int n) {
    if (n < 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (this.pattern[i] && n - i >= 0) {
        cnt += steps(n - i);
      }
    }
    return cnt;
  }
}
