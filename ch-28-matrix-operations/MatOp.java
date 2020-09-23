public class MatOp
{
	public static double[]
		LUPsolve(double[][] l, double[][] u, double[] p, double[] b)
	{
		int n = l.rows; // check for it later
		
		double x[] = new double[n];
		double y[] = new double[n];
		for (int i = 0; i < n; i++)
		{
			double sum = b[p[i]];
			for (int j = 1; j <= i - 1; j++)
				sum -= l[i][j] * y[j];
			y[i] = sum;
		}
		for (int i = n; i > 0; i--)
		{
			double sum = y[i];
			for (int j = i + 1; j <= n; j++)
				sum -= u[i][j] * x[j];
			x[i] = sum / u[i][j];
		}
			
		return x;
	}

	public static void main(String args[])
	{
		double a[][] = new double[3][3];
		double b[][] = new double[3][3];

		double x[] = LUPsolve(a, b);	
		for (int i = 0; i < x.length; i++)
			System.out.println(x[i]);
	}
}

