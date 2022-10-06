import java.util.*;

public class SelectionSort {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of elements in the array");
        int n = sc.nextInt();
        int []arr = new int[n];
        System.out.println("Intially array is");
        for(int i=0;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
			selection_sort(arr);
			System.out.println("Finally sorted array is");
			for(int i=0;i<arr.length;i++)
			{
				System.out.print(" "+arr[i]);
			}
				System.out.println();

		}
  
	public static void selection_sort(int arr[])
	{
		for(int i=0;i<arr.length-1;i++)
		{
			int min =arr[i];
			int p=i;
			for(int j=i+1;j<arr.length;j++)
			{
				if(arr[j]<min)
				{
					min=arr[j];
				    p=j;
				}
			}
			int tem=arr[p];
			arr[p]=arr[i];
			arr[i]=tem;
		}
	}
}

