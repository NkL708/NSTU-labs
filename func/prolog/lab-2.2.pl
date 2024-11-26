shift_list([], _, []) :- !.
shift_list(List, 0, List) :- !.
shift_list([Head|Tail], N, Result) :- 
    append(Tail, [Head], Temp),
    N_new is N - 1,
    shift_list(Temp, N_new, Result).

shift_lists([], _, []) :- !.
shift_lists([Head|Tail], Num, [Head2|Tail2]) :-
    shift_list(Head, Num, Head2),
    shift_lists(Tail, Num, Tail2).

% My version 
% shift_list(0, List, List_to_move, Result) :-
%     append(List, List_to_move, Result).
% shift_list(Length, [Head|Tail], List_to_move, Result) :-
%     append(List_to_move, [Head], Temp),
%     shift_list(New_length, Tail, Temp, Result).
