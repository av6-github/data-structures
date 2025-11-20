import java.util.*;

public class setAssociative {

    static int[] cacheUpdate(int []cacheMemory,int n,int [][]mainMemory)
    {
        int tempRow = 0;
        int tempCol = 0;
        for (int i = 0 ; i < mainMemory.length ; i++) {
            for(int j = 0 ; j < mainMemory[i].length ; j++){
                if(mainMemory[i][j] == n){
                    tempRow = i;
                    tempCol = j;
                }
            }
        }
        int index = (2*tempRow) % cacheMemory.length;
        int indexNext = index+1;
        if(indexNext == cacheMemory.length){
            indexNext = 0;
        }
        if(tempCol == 1){
            cacheMemory[index] = mainMemory[tempRow][tempCol-1];
            cacheMemory[indexNext] = mainMemory[tempRow][tempCol];
        }
        else{
            cacheMemory[index] = mainMemory[tempRow][tempCol];
            cacheMemory[indexNext] = mainMemory[tempRow][tempCol+1];
        }
        return cacheMemory;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [][]mainMemory = {{1,2},{3,4},{5,6},{7,8},{9,10}};
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
                cacheMemory = cacheUpdate(cacheMemory,choice,mainMemory);
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