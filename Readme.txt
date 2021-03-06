????:
----

 "??????? ????????? ??????? ?? ??? ??????????? ?????".


??????? ??????:
--------------

??? ?????? (?????????) ????? ????? ? ????????? [1; 10^9], ????? ??????? ?? 2 ?? 10^5. ?????????? ????????? ??? ?? ??? ????????????, ??? ????? ????? ????? ? ?????? ?? ??? ???? ?????????.


??????????:
----------

   - halfSumFinder - ?????????, ???????? ???????????? ??????. ????????? ????? ?? ???????????? ?????, ?????? ?? ??????????? ????? ?????: "??/???" ? ?????? ?????, ???????? ? ?????? ????????????.

   - hsfTester - ?????????, ??????????? ????? ???????. ?????????? ????? ??????? ??????? ??????, ??? ??????? ?? ??? ???????? ???????? ???????, ??????? ?? ????? ??????????: ??????????? ?????, ????? ????????????? ????????? ? ?.?.

   - hsfSearchOrderDemo - ?????????, ??????????????? ??????? ???????? ????????? ???????. ??????????, ??? ??????? ?????????? ????????? ? ? ????? ?????????????.

   - hsfInputGenerator - ?????????, ???????????? ?????? ??????? ??????. ?????????? ????? ??????? ?????? ? ?????? ??? ?? ??????????? ????? (????? ?? ???? ????? ???? ?????????? ? ????????? ? ?????).

   - hsfOutputVerifier - ?????????, ??????????? ???????????? ???????. ?????? ?? ?????? ????? ???????? ??????, ?? ??????? - ????????? ?????? halfSumFinder'?, ????????? ????? ??? ??????? ? ??????? ??? ?????????? ?????.


???????:
-------

1. ????????? ??????? ?????? x[i], i: [0;N).

2. ??????? ????????? ????? sum[i] = sum (x[j]), j: [0;i].

3. ???? totalSum = sum[N-1] - ????????, ?? ??????? ?? ?????????? (?????????? ????????? ?????? ???????).

4. ????? ?????? ? (???????????????) ??????? ????????? ???? ???????? desired = totalSum / 2, ??? ????? ?????? ?????? ilb = lower_bound (desired).

5. ???????? ???????????????? ???????? ??????? x ? ????????? [0;ilb] ??????? ? 1-?? ????????????, ????????? (? ????????? [ilb+1;N)) - ?? 2-??. ???? sum[ilb] == desired, ?? ??????? ???????.

6. ????? ???? "?????????" diff = sum[ilb] - desired, ??????? ?????????? ??????? ?? 1-?? ????????????. ??? ????????, ???? x[0] <= diff <= sum[ilb-1]. ? ???? ??????, ???????? ???????? ?????????? ? ???? 4, ????????? diff ? ???????? desired (??? ???? ???????? ????? ?????????????? ?? ????????????? ????????: ? ???????? ????????? - ?? 2-??, ? ???????? - ? 1-??), ? ????????, ??? ??, ? ?????, ?????????? ?? ???? 5.

7. ???????? ???????? ??????????????? ??????? ?????? ?? ??? ?????: ?????, ? ????????? [0;ilb-1], ? ?????? - ? ????????? [ilb;N). ?? ?????????? ????? ?? ???????? ??? ?????? ?????, ? ?????????????? ?????????: x[ilb] - ? 1-? ????????????, ????????? - ?? 2-?, ????????? ??????????????? ?? ????????????? ????????? ? ????? ?????, ? ? ??? ?? ??????????. ????????? ?????? ??????? ?? ?? ????? ??? ?????? ????????? ????????????? ????????? ? ?????? ?????. ???? ??? ???????? ????????? (???? ??? ??????? ???????? ??????? ??????????? ??????????, ?.?. ?? 2^(N-ilb)), ??????, ??????? ?? ?????????? ???, ???? ??? ??? ??????????? ?????, ???? ????????? ?? ??????? ?????.


??????? ????????
----------------

   ??? ???????????? ???? 7 ?????????????? ????????? ????????? ??????: ? ????? ??????? ?????????? ????????????? ????????? ? ?????? ?????, ????? ????????? ????? ???????? ????????, ?????????? ?????????????? ????????????? ???????? 100000... ("1" - ? 1-?? ????????????, "0" - ?? 2-??), ????? ?????????? ? ??????? ????????? ?????: 1000..., 0100..., 1100..., 0010... ? ?.?. ??? ???? ?????????? ????????? ???????????? (???????????? ?????? ??????) ???????? ?????. ??????, ??? ???? ?????? ?????? ????? ??????, ??? ????? ???? ??????????. ? ??? ? ????
   ???? 10^5 ????? ?????????? ???????????? ? ????????? [0;10^9] ? ?????????????, ?? ??????? ?????????? ????? ????? ????????? ??????? 10^9 / 10^5 = 10^4, ?.?., ? ???????? ??????? x ????? ????? ?????: 500000000, 500010000, 500020000, 500030000 ? ?.?. ? ???? ????????? (1/10 ?????) ????? ???-?? ?????: 100000000, 100010000, 100020000, 100030000 ? ?.?. - ?.?, ??????? ????? ????? ???????, ???????????? ??????????, ??? ???????, ??????? ?????? ?? ????? ? ?????????, ??????? ?? ??????? ?????????? ?? ??????: 1000..., 0100..., 0010..., 0001... ? ?.?., ? ????? ??? 1100...
   ??????, ?????? ??????????, ??????? ?? ????????, ??? ?? ??? ??????????, ?????? ?? ????????????? 1010..., ????? ?? ????????? ?? ??? ???? ??????? ?????: 1001... ??? 0110..., ??????? ??? ???????? ????????????? ? ??????? ??????????? "?????????" ???? ???????????? priority_queue, ? ???????, ?????? ?? ????????????? 1000..., ???????? ??????? 1100... (??? ????????????), ? ????? 0100..., 0010..., 0001... ? ?.?.

??????? ???????? ????????????? (????????? ???????? ????? ??????):

1) ?????? ????????? ?????? ??????????? ???????? 100000... (?????? ??????? ????????? ??????? ? ?????? ?????????, ????????? - ? ???????) ? ????????? ????????? ?????? ???????? ??????? ("curII"), ?????? 2, ?.?. ??????????? ?? ?????? ????? ????.

2) ??? ??????? ???????, ?????????? ?? ????????????? ????? ?????? ? ?????? ???? - "11...1000..." - ? ? ????????? ????????? curII (??????????? ?? ?????? ????? ????), ??????? ????? ?????????, ???????? ? ????????? ????????? ???????, ?.?., ??????? ?????? ????? ???? ?? ??????? (?? 1000... ???????? 1100..., ?? 1100... ???????? 1110... ? ?.?.) ? ?????????? curII ????????? ???????? (??????????? ?? ?????? ????? ????). ??? ???? curII ???????? ????????? ??????????? ?? 1 (???????? ????????? ?? ?????? ?????? ???????). ???? ?? ?????? ???????? ??? ??????? (??? ???????? ????????? ???????? ? ?????? ?? ????????) - ?????????? ????????? ?? ??????????.

3) ??? ??????? ?????????, ??????????? ?????? ? ???????????? ??????? ????? ? ?????? ? curII, ??????????? ?? ?????-?????? ???????, ???????? "???????????" ??? ??????? ?????? ?? ???? ???????: ?? 1000... ???????? 0100..., ?? 0100... ???????? 0010... ? ?.?., ? curII ?????? ????????? ????????????? ?? ???????????? ???????. ??? ???? curII ???????? ????????? ?????????? ?? ????????? ??????? ????? ?? ???????. ???? ??????????? ??????? ?????? ?????????? (??? ?????????? ????????? ??????? ????????? ??? ?????? ?? ??? ??? ????? ???????), ???? ????? ?? ??????? ?????? ???????, "??????????". ???? ????? ??????? ?? ???????, ?????????? ????????? ?? ??????????.

????? ??????? ???????? ????????? ?? ??????? ????????????. ?????????? hsfSearchOrderDemo ?????????? ??????? ???????? ???????? ? ??????????? ????????????, ? ????? ????????????, ??? ????????? ??????????? ?? priority_queue ? ??????? ??????????? "?????????" (?.?., ??????? ?? ????????? ?? ???????? ???) ? ?? ???? ????????? ?? ??????????????? ?????? (??? ????????????? ?????????? ??? ????????????? ?? ??? ?????????? ? priority_queue, ?? ?? ????? ??????? ??????????). ?????? ????????? ? ????? ??????? ??? ?????? ?????????? ? ??????? '------------'.


??????????? ?????????? ?????? ????????????? ????????? ?? ????????????? (SetImpl).
--------------------------------------------------------------------------------

   ??????? ????????? ???????????? ??????????, ? ???? ?????? ????? ?????, ?????? ?? ??????? ?????????? ???-?? ????????? ?????????, ? ????????? - ?? ??????? ? ??????????????? ??????? ???????. ??? ??????? ????????? ? ????? ???? (pool) - ??????? ????? ?????.
   ???? ??? ????????? ?????? ????????? ???? ??????????? ?????? ????????? ???????, ?? ????? ?????? ????????? ?? ?????????, ? ???????????????? ???????, ????????????, ??? ?? ????? ????????? ?????? ????????? ??????.
   ???? ????? ??? ???????? SetImpl - ??? ????????? ??????.