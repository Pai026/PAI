import math
def lcm(nums):
    a = nums[0]
    b = nums[1]
    curr_lcm = a*b//math.gcd(a,b)
    for num in nums[2:]:
        curr_lcm = curr_lcm*num//math.gcd(curr_lcm,num)
    return curr_lcm
try:
    T = int(input())
    T=T//2
    points = {"Darrell":0,"Sally":0}
    for cases in range(T):
        question_input = input()
        
        question_input = question_input.split()
        questioner = question_input[0]
        if(cases == 0):
            first_questioner = questioner
        number_string = question_input[1]
        nums = list(map(int,number_string.split(',')))

        assert(2<=len(nums)<=7)
        for num in nums:
            assert(1<=num<=100)
        print(f"{questioner}'s question is : {number_string}")
        answer_input = input().split()
        answerer = answer_input[1]
        if(case == 0):
            second_questioner = answerer
        correct_answer = lcm(nums)
        if answer_input[2] != 'PASS':
            ans =int(answer_input[2])
            if(ans == correct_answer):
                print('Correct Answer')
                print(f'{answerer} : 10points')
                points[answerer]+=10
            else:
                print('Incorrect Answer')
                print(f'{answerer} : 0points')
        
        else:
            print("Question is PASSed")
            print(f'Answer is {correct_answer}')
            print(f'{answerer}: 0points')
        if(case == N-1):
            print('Total Points')
            print(f'{first_questioner}: {points[first_questioner]}points')
            print(f'{second}: {point_dictionary[second]}points')
            if points["Darrell"] == points["Sally"]:
                print('Game Result: Draw')
            elif points["Darrell"] > points["Sally"]:
                print('Game Result: Darrell is Winner')
            else:
                print('Game Result: Sally is Winner')
except:
    print("Invalid Input")