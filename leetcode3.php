<?php
/**
 *Author:Goson
 *Time:2017/4/13
 *这道题写了很久，问题的关键就是两点:
 *1.如何把字符和它前面的每个字符进行比较
 *2.如果和前面的字符重复了，那么开头的字符直接跳转到重复字符的后面一位，而不是接着往下循环
 *由于leetcode不支持PHP，所以代码可能存在大量漏洞( ◉ืൠ◉ื)
 */


//从前往后寻找，如果该下标对应的值与前面某一个下标对应的值相同，就把$start的值变为前面的下标+1
//
while (fscanf(STDIN, "%s", $str)) {
    flush();                    //清空缓冲区
    $length = strlen($str);     //字符串的长度
    $max = 1;                   //最大子字符串的长度
    $start = 0;                 //起始点
    $end = 1;                   //终止点

    while ($end < $length) {    //终止点的坐标不能无限往后移动
        $start_back = $start;   //创建一个$start的副本用于循环

        #没错！
        while ($start_back < $end) {    //比较这个字符之前的所有字符即可
            if ($str[$start_back] == $str[$end]) {      //如果前面有字符和这个字符相同
                $start = $start_back+1;     //把起点移动到前面相同的那个字符的后面一位
                break 1;
            }
            $start_back++;
        }

        if ($max < ($end-$start+1)) {     //更新一下最大长度
            $max = $end-$start+1;
        }
        $end++;
    }

    echo $max."\n";
}