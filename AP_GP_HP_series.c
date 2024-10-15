/* 
AP : An arithmetic progression (AP) or arithmetic sequence is a sequence of numbers such that the difference between the consecutive terms is constant.
Let's say, the sequence 2, 5, 8, 11, 14, 17...... is an arithmetic progression with common difference of 3.
GP : A geometric progression (GP), also known as a geometric sequence, is a sequence of numbers where each term after the first is found by multiplying the previous one by a fixed non-zero number called the common ratio.
For example, the sequence 2, 6, 18, 54, ... is a geometric progression with common ratio 3.
HP : A harmonic progression (HP) or harmonic sequence is a progression formed by taking the reciprocals of an arithmetic progression.
 */

#include<stdio.h>
int main(){
    float first, R, N, AP, GP, HP, A_ap, A_gp, A_hp;
    
    // read the first integer, common difference or common ratio, and total number of terms to be generated in all AP, GP, HP from user.
    printf("Enter the First Number 'start': ");
        scanf("%g", &first);
        
    printf("Enter the Common Difference / Ratio 'R': ");
        scanf("%g", &R);

    printf("Enter the number of terms 'N': ");
        scanf("%g", &N);
    
    /* Assign the first number to AP, GP and HP separately.
    Because when we use "first" in finding AP directly and then use "first" in finding GP the modified "first" in AP might get reflected in GP or HP too.
    Hence, to avoid conflicts assign first number from where the series starts i.e, "first" to 3 different variables.
    */
    A_ap = first;
    A_gp = first;
    A_hp = first;

    if(first>0 && R>0 && N>0){
        printf("AP = %g ", first);

        // for loop to generate arithmetic progression and print them.
        for(int i=1; i<N; i++){
            AP = A_ap + R;
            printf("%g ", AP);
            A_ap = AP;
        }     
        printf("\n");
    
        printf("GP = %g ", first);

        // for loop to generate geometric sequence and print them.
        for(int i=1; i<N; i++){
            GP = A_gp * R;
            printf("%g ", GP);
            A_gp = A_gp * R;
        }
        printf("\n");
    
        printf("HP = ");

        // for loop to generate harmonic sequence and print them.
        for(int i=1; i<=N; i++){
            HP = 1/A_hp;
            printf("%f ", HP);
            A_hp = A_hp + R;
        }
    }
    //  if the input by user is invalid print error message.
    else{
        printf("ERROR : Invalid input");
    }
    return 0;
}