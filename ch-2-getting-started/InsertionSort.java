// 9/22/2020 9:39:17 PM
public class InsertionSort
{
	public static void InsertionSortUp(int arr[])
	{
		//int how_many = 0;
		for (int j = 1; j < arr.length; j++)
		{
			int key = arr[j];
			int i = j - 1;
			while (i >= 0 && arr[i] > key)
			{
		//		how_many ++;
				arr[i + 1] = arr[i];
				i--;
			}
			arr[i + 1] = key;
		}
		//System.out.println(how_many);
	}

	public static void InsertionSortDown(int arr[])
	{
		for (int j = 1; j < arr.length; j++)
		{
			int key = arr[j];
			int i = j - 1;
			while (i >= 0 && arr[i] < key)
			{
				arr[i + 1] = arr[i];
				i--;
			}
			arr[i + 1] = key;
		}
	}

	public static void main(String[] args)
	{
		int k = Integer.parseInt(args[0]);
		int arr[] = new int[k];
		for (int i = k; i > 0; i--)
			arr[k - i] = i;
		int n = arr.length;
		// sort
		long i = System.currentTimeMillis();
		InsertionSortUp(arr);
		long j = System.currentTimeMillis();
		System.out.println(j - i);
	}
}

