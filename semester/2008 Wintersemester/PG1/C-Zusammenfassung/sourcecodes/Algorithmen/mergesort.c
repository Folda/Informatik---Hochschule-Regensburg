void MergeSort(int liste[], int groesse){
 
     if(groesse > 1){
 
         int haelfte1[groesse/2];
         int haelfte2[(groesse + 1)/2];
         int i;
         for(i = 0; i < groesse/2; ++i)
             haelfte1[i] = liste[i];
         for(i = groesse/2; i < groesse; ++i)
             haelfte2[i - groesse/2] = liste[i];
 
         MergeSort(haelfte1,groesse/2);
         MergeSort(haelfte2,(groesse + 1)/2);
 
         int *pos1 = &haelfte1[0];
         int *pos2 = &haelfte2[0];
         for(i = 0; i < groesse; ++i){
             if(*pos1 <= *pos2){
                 liste[i] = *pos1;
                 if(*pos1 == haelfte1[groesse/2 - 1]){
                     pos1 = &haelfte2[(groesse + 1)/2 - 1];
                 }
                 else{
                     ++pos1;
                 }
             }
             else{
                 liste[i] = *pos2;
                 if(*pos2 == haelfte2[(groesse + 1)/2 - 1]){
                     pos2 = &haelfte1[(groesse)/2 - 1];
                 }
                 else{
                     ++pos2;
                 }
             }
         }
     }
 }
