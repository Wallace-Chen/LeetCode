class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Bit operation, xor can detects (flag) when 1 appears odd number of times. But in this case, we need to distinguish the 1 times from 3 times. Since only two states available for each binary bit, we need thus two bits (thus allow 4 states) for each bit detection, in other words, we use two variables.
        // Recall in Problem 136, we have one variable. Each bit in this variable help us distinguish the odd from even number of times.
        // Now, we use two variables, seen_once, seen_twice. Bit in seen_once is 1 only when 1 in this bit position appears 1 time. Bit in seen_twice is 1 only when 1 in this bit position appears 2 times. Construct the following transformation rules:
        //seen_once = (seen_once ^ num) & (~seen_twice);
        //seen_twice = (seen_twice ^ num) & (~seen_once);
        // Note the order is very important here. You must update seen_once variable before updting seen_twice. (~seen_twice) is used to notify seen_once to ignore when 1 is about to appear 3 times. (Remember 1 should have appeared already two times in order to appear 3 times.) (~seen_once) is used to make xor operation detect even times of appearance instead of odd times. The corresponding transformation table is below:
        // Number of appearance:        0 time,  1 time,  2 times,  3 times
        //seen_once:                    0       ,1      , 0        ,0
        //seen_twice:                   0       ,0      , 1        ,0
        // In fact, you can come up with other transformations as long as they give the above table.
        //As you can see, having the above transformation gives 3 different states (mod 3) instead of only 2 states if using 1 variable (mod 2). If we want to distinguish 1 from 5 number of times, we need to have the following table using 3 variables:
        // Number of appearance:        0 time,  1 time,  2 times,  3 times,  4 times   5 times
        //first_bit:                    0       ,1      , 0        ,1         ,0        0
        //second_bit:                   0       ,0      , 1        ,1         ,0        0
        //third_bit:                    0       ,0      , 0,       ,0         ,1        0
        // This table could let us distinguish 5 states, and any bit (first_bit, second_bit, third_bit) will be 0 as long as 1 appears 5 times or 5n times. One of possible transformation rules are below as an example:
        // first_bit = (first_bit ^ num) & (~third_bit);
        // second_bit = (first_bit & second_bit | ~first_bit & (second_bit ^ num)) & (~third_bit)
        // third_bit = (third_bit ^ num) & (~(first_bit | second_bit))
        int first_bit = 0, second_bit = 0;
        for(auto num:nums){
           first_bit = (first_bit ^ num) & (~second_bit);
           second_bit = (second_bit ^ num) & (~first_bit);
        }
        return first_bit;
    }
    
    // Wrong:
    //Thus it can be generalized to 2k+1 times of appearance situation, BUT be carefully when 2k+1=7, since 7mod3 = 1, in this case we cannot use above transformation to distinguish 1 and 7 number of times. However we could use the similiar idea, and propose different transformation rules to have the following table:
        // Number of appearance:        0 time,  1 time,  2 times,  3 times,  4 times
        //first_bit:                    0       ,1      , 0        ,1         ,0
        //second_bit:                   0       ,0      , 1        ,1         ,0
        // This table could let us distinguish 4 states, which can work actually in any values. The possible transformation rule is below (quite ugly but only for demonstration purpose):
        //second_bit = ((second_bit & ~first_bit) | (second_bit ^ num)) & ((first_bit ^ second_bit) | (first_bit & second_bit));
        //first_bit = first_bit ^ num;
        // To distinguish 1 time and 3 times, we simply do first_bit ^ second_bit before the return. See code blow for example.
};
