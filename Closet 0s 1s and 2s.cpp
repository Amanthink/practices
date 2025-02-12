  {
        // Your Code Here
        
        int left=0,centre=0,right=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) left++;
            else if(arr[i]==1) centre++;
            else right++;
        }
        int i=0;
        while(left>0){
            arr[i]=0;
            i++;
            left--;
        }
        while(centre>0){
            arr[i]=1;
            i++;
            centre--;
        }
        while(right>0){
            arr[i]=2;
            i++;
            right--;
        }
        
    }
};
