import java.util.Scanner;

public class cacheMapping {

    static int cachePointer = 0;

    static int[] cacheUpdate(int []cacheMemory,int n)
    {
        cacheMemory[cachePointer] = n;
        cachePointer ++;
        if(cachePointer == cacheMemory.length){
            cachePointer = 0;
        }
        return cacheMemory;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int []mainMemory = {1,2,3,4,5,6,7,8,9,10};
        int []cacheMemory = new int[5];
        int totalSearches = 0;
        int hits = 0;
        while (true) {
            int found = 0;
            totalSearches++;
            System.out.print("\n\nEnter A Number Between (1-10) ('-1' to exit) : ");
            int choice = sc.nextInt();
            if(choice == -1){
                System.out.println();
                totalSearches--;
                break;
            }
            for (int i : cacheMemory) {
                if (i == choice) {
                    System.out.print("\t Cache Hit || ");
                    found = 1; 
                    hits++;
                }
            }
            if(found == 0){
                if(choice < 1 || choice >10){
                    System.out.println("\nNOT FOUND IN MAIN MEMORY");
                    totalSearches--;
                    continue;
                }
                System.out.print("\t Cache Miss || ");
                cacheMemory = cacheUpdate(cacheMemory,choice);
            }
            
            for (int i : cacheMemory) {
                System.out.print("\t"+i);
            }
        }
        double hitRatio = (double)hits / totalSearches;
        System.out.println("\nHit Ratio : " + hits + "/" + totalSearches);
        System.out.println("\nHit Ratio : "+hitRatio);
        
    }
}
