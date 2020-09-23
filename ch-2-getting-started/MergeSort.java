// 9/23/2020 1:21:10 AM
public class MergeSort
{
	private static void Merge(int arr[], int p, int q , int r)
	{
		int i, j, k;
		int n1 = q - p + 1;
		int n2 = r - q;
		int L[] = new int[n1 + 1];
		int R[] = new int[n2 + 1];
		for (i = 0; i < n1; i++)
			L[i] = arr[p + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[q + j + 1];
		L[n1] = 100000001; // this is enfinity :)
		R[n2] = 100000001; // sentinal
		i = 0;
		j = 0;
		for (k = p; k <= r; k++)
			if (L[i] <= R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
	}

	private static void Merge2(int arr[], int p, int q , int r)
	{
	// 9/23/2020 11:33:48 AM
		int i, j, k;
		int n1 = q - p + 1;
		int n2 = r - q;
		int L[] = new int[n1];
		int R[] = new int[n2];
		for (i = 0; i < n1; i++)
			L[i] = arr[p + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[q + j + 1];
		i = 0;
		j = 0;
		for (k = p; k <= r && i < n1 && j < n2; k++)
			if (L[i] <= R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			if (j == n2)
				for ( ; k <= r; k++)
				{
					arr[k] = L[i];
					i++;
				}
			else
				for ( ; k <= r; k++)
				{
					arr[k] = R[j];
					j++;
				}
	}

	public static void MergeSort(int arr[], int p, int r)
	{
		if (p < r)
		{
			int q = (p + r) / 2;
			//System.out.println(q);
			MergeSort(arr, p, q);
			MergeSort(arr, q + 1, r);
			Merge2(arr, p, q, r);
		}
	}

	public static void main(String args[])
	{
		int k = Integer.parseInt(args[0]);
		int arr[] = new int[k];
		for (int i = k; i > 0; i--)
			arr[k - i] = i;
		int n = arr.length;
		// sort
		long i = System.currentTimeMillis();
		MergeSort(arr, 0, n - 1);
		long j = System.currentTimeMillis();
		System.out.println(j - i);
		//for (int c = 0; c < k; c++)
		//	System.out.println(arr[c]);
	}
}

