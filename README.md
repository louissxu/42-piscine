# 42-piscine

Repository of my progress in the 42Adel November Piscine 2021. Piscine dates from 2021/11/22 to 2021/12/19.

The [project]-dev folder is my working directory for my project where I build the project. If you want to follow my git commits/changes etc you can see them in this folder. This is generally the most up to date repo including any changes I have made after submission (if I decided not to resubmit it). This directory also includes files that I would like to keep but are not able to be submitted (the subject pdf's, my test files, etc).

The [project] folder is my "submission" folder of files in the state that I am submitting them to the vogsphere. The corresponding moulinette grading/scoring is below.

<table border = "1" cellpadding = "4" cellspacing = "0">
<thead><tr>
<th align = "left">Project</th>
<th>Moulinette Grade</th>
<th>Exercise pass/fail</th>
<th>Comments</th></th>
</tr></thead>
<tbody>

<tr valign = "top">
<td>C02 - Submission 1</td>
<td>5% (fail)</td>
<td>ex00: OK | ex01: KO | ex02: OK | ex03: OK | ex04: OK | ex05: OK | ex06: OK | ex07: OK | ex08: OK | ex09: OK | ex10: KO | ex11: KO | ex12: KO</td>
<td>
    <ul>
        <li>ex02: Need to null terminate up to the expected n bytes. Not just put a single null terminator.</li>
    </ul>
</td>
</tr>

<tr valign = "top">
<td>C02 - Submission 2</td>
<td>65% (pass)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: OK | ex04: OK | ex05: OK | ex06: OK | ex07: OK | ex08: OK | ex09: OK | ex10: KO | ex11: KO | ex12: KO</td>
<td>
    <ul>
        <li>ex10: To match inbuilt implementation, need to only null terminate once, not the full n bytes. Fixed.</li>
        <li>ex11: Unsure. But switched the non-printable check to only consider known non printables as such (in case they pass an unsigned char and use the extended ascii array. Fixed if this is the issue.</li>
        <li>ex12: Returning addr pointer after moving the pointer around. No longer points to start of memory being printed. Fixed.</li>
    </ul>
</td>
</tr>

<tr valign = "top">
<td>C04 - Submission 1</td>
<td>70% (pass)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: OK | ex04: KO | ex05: OK</td>
<td>
    <ul>
        <li>ex04: Char for 0 val was hardcoded as "0" char rather than base[0]</li>
    </ul>
</td>
</tr>

<tr valign = "top">
<td>C04 - Submission 2</td>
<td>100% (pass)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: OK | ex04: OK | ex05: OK</td>
<td></td>
</tr>

<tr valign = "top">
<td>C05 - Submission 1</td>
<td>50% (pass)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: OK | ex04: OK | ex05: OK | ex06: KO | ex07: Timeout | ex08: OK</td>
<td>
    <ul>
        <li>ex06: Forgot that 2 is prime</li>
        <li>ex07: Not sure what the timeout error is from. From deeptrace, all the tests pass and provide the correct solution. Maybe the solution is too inefficient and there is some upper ceiling of allowed compute time even if it passes all the tests?</li>
    </ul>
</td>
</tr>

<tr valign = "top">
<td>C06 - Submission 1</td>
<td>70% (pass)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: KO</td>
<td>
    <ul>
        <li>ex03: ?? Not sure. Will need to do more debugging as to why this failed.</li>
    </ul>
</td>
</tr>

<tr valign = "top">
<td>C07 - Submission 1</td>
<td>-42% (fail)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: OK | ex04: Cheating | ex05: KO</td>
<td>
    <ul>
        <li>ex04: Used realloc like a silly person and failed due to forbidden function use.</li>
        <li>ex05: Didn't null terminate strings.</li>
    </ul>
</td>
</tr>

<tr valign = "top">
<td>C07 - Submission 2</td>
<td>100% (pass)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: OK | ex04: OK | ex05: OK</td>
<td></td>
</tr>

<tr valign = "top">
<td>C08 - Submission 1</td>
<td>0% (fail)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: Norme error | ex04: Norme error | ex05: Norme error</td>
<td>
    <ul>
        <li>ex03: Forgot to norm</li>
        <li>ex04: Forgot to norm</li>
        <li>ex05: Forgot to norm</li>
    </ul>
</td>
</tr>

<tr valign = "top">
<td>C08 - Submission 2</td>
<td>100% (pass)</td>
<td>ex00: OK | ex01: OK | ex02: OK | ex03: OK | ex04: OK | ex05: OK</td>
<td></td>
</tr>

<tr valign = "top">
<td>C09 - Submission 1</td>
<td>60% (fail)</td>
<td>ex00: OK | ex01: OK | ex02: Segmentation fault</td>
<td>
    <ul>
        <li>ex02: Didn't handle the situation when the separators string is empty.</li>
    </ul>
</td>
</tr>

<tr valign = "top">
<td>C09 - Submission 2</td>
<td>100% (fail)</td>
<td>ex00: OK | ex01: OK | ex02: OK</td>
<td>
</td>
</tr>

</tbody>
</tbody>
</table>

## Exams
Questions I got from the exams

<table border = "1" cellpadding = "4" cellspacing = "0">
<thead><tr>
<th align = "left">Exam</th>
<th>Moulinette Grade</th>
<th>Exam questions</th>
<th>Comments</th></th>
</tr></thead>
<tbody>

<tr valign = "top">
<td>Exam 00</td>
<td>100% (pass)</td>
<td>
    <ol start="0">
        <li>only_a</li>
        <li>ft_print_numbers</li>
        <li>maff_alpha</li>
        <li>ft_swap</li>
        <li>ft_strcpy</li>
        <li>ft_atoi</li>
    </ol>
</td>
<td>Questions were worth 16 points, except the last one which was worth 20.</td>
</tr>

<tr valign = "top">
<td>Exam 01</td>
<td>100% (pass)</td>
<td>
    <ol start="0">
        <li>only_z</li>
        <li>ft_strlen</li>
        <li>rot_13</li>
        <li>wdmatch</li>
        <li>ft_range</li>
        <li>ft_split</li>
    </ol>
</td>
<td>Introduction to argument parsing in rot_13. Adds dynamic memory allocation in ft_range.</td>
</tr>

<tr valign = "top">
<td>Exam 02</td>
<td>100% (pass)</td>
<td>
    <ol start="0">
        <li>aff_a</li>
        <li>ft_strlen</li>
        <li>ulstr</li>
        <li>last_word</li>
        <li>ft_atoi</li>
        <li>ft_rrange</li>
        <li>sort_list</li>
    </ol>
</td>
<td>Sort list adds structs/user defined types. Also adds passing a function as an argument to another function. Asks for implementation of a linked list sort after being given a comparator function. This exam also had 7 questions. First 6 were worth 14 points. Last question was worth 16 points.</td>
</tr>

<tr valign = "top">
<td>Exam 03</td>
<td>90% (pass)</td>
<td>
    <ol start="0">
        <li>aff_a</li>
        <li>ft_countdown</li>
        <li>ft_strlen</li>
        <li>buzzfizz</li>
        <li>aff_first_param</li>
        <li>rot_13</li>
        <li>ft_strcmp</li>
        <li>ft_strrev</li>
        <li>ft_atoi</li>
        <li>union</li>
        <li>ft_range</li>
        <li>ft_split</li>
        <li>count_alpha</li>
        <li>ord_alphlong</li>
        <li>infin_multi</li>
    </ol>
</td>
<td>Exam is 8 hours rather than the 4 previously. However, I had to start late so I only had 5 hours to complete the exam. Questions are worth 6 points except for the last question which is worth 10 points. Ran out of time, completed the second to last question but only had <5 minutes left for the final question so was unable to make an attempt.
   </td>
</tr>
    
</tbody>
</tbody>
</table>
