:- encoding(utf8).

% From 5 to n (only odd)
sum_tail(End_sum, Num, Result_tmp, Result) :-
    Num >= End_sum,
    New_result is Result_tmp + Num,
    New_num is Num - 2,
    !,
    sum_tail(End_sum, New_num, New_result, Result). 
sum_tail(_, _, Result_tmp, Result) :- 
    Result is Result_tmp.

sum(5, 5) :- !.
sum(Num, New_result) :-
    New_num is Num - 2,
    sum(New_num, Result),
    New_result is Result + Num.
