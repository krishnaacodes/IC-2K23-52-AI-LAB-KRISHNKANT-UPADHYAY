domains
    road = symbol

predicates
    traffic(integer, road, integer, integer, integer, integer)
    road_rank(road, integer)
    priority(integer, road, integer)
    score(integer, road, integer)
    winner(integer, road)
    run_test(integer)
    show_reason(integer, road)

clauses

    traffic(1, a, 15, 5, 0, 0).
    traffic(1, b, 8, 12, 1, 0).
    traffic(1, c, 25, 3, 0, 0).
    traffic(1, d, 5, 7, 0, 0).

    traffic(2, a, 10, 5, 0, 0).
    traffic(2, b, 18, 4, 0, 0).
    traffic(2, c, 25, 6, 0, 0).
    traffic(2, d, 12, 6, 0, 0).

    traffic(3, a, 30, 10, 0, 1).
    traffic(3, b, 12, 8, 0, 0).
    traffic(3, c, 12, 8, 0, 0).
    traffic(3, d, 6, 15, 0, 0).

    road_rank(a, 4).
    road_rank(b, 3).
    road_rank(c, 2).
    road_rank(d, 1).

    priority(C, R, 100) :-
        traffic(C, R, V, W, 1, 0),
        V >= 0,
        W >= 0.

    priority(C, R, 0) :-
        traffic(C, R, V, W, 0, 1),
        V >= 0,
        W >= 0.

    priority(C, R, 40) :-
        traffic(C, R, V, W, 0, 0),
        V >= 20,
        W >= 0.

    priority(C, R, 30) :-
        traffic(C, R, V, W, 0, 0),
        V >= 10,
        V < 20,
        W >= 0.

    priority(C, R, 20) :-
        traffic(C, R, V, W, 0, 0),
        V < 10,
        W >= 10.

    priority(C, R, 10) :-
        traffic(C, R, V, W, 0, 0),
        V < 10,
        W < 10.

    score(C, R, S) :-
        priority(C, R, P),
        road_rank(R, K),
        S = P * 10 + K.

    winner(C, R) :-
        score(C, R, S),
        score(C, a, SA),
        score(C, b, SB),
        score(C, c, SC),
        score(C, d, SD),
        S >= SA,
        S >= SB,
        S >= SC,
        S >= SD.

    show_reason(C, R) :-
        traffic(C, R, V, W, 1, 0),
        V >= 0,
        W >= 0,
        write("Emergency vehicle detected."),
        nl,
        write("Emergency has highest priority."),
        nl.

    show_reason(C, R) :-
        traffic(C, R, V, W, 0, 1),
        V >= 0,
        W >= 0,
        write("Road is blocked. It is not selected."),
        nl.

    show_reason(C, R) :-
        traffic(C, R, V, W, 0, 0),
        V >= 0,
        W >= 0,
        write("Selected according to traffic priority."),
        nl.

    run_test(C) :-
        nl,
        write("SMART TRAFFIC SIGNAL CONTROLLER"),
        nl,
        winner(C, R),
        write("Selected Road: "),
        write(R),
        nl,
        write("Signal: GREEN"),
        nl,
        write("Reason:"),
        nl,
        show_reason(C, R),
        nl.

goal
    run_test(1),
    run_test(2),
    run_test(3).
