<?php
/**
 *Author:Goson
 *Time:2017/4/13
 *这道题让自己发现了PHP中除法并非整数除法，而是精确除法。然后复习了函数。
 *既然存在第三个数组里面，那么循环的条件就应该以第三个数组的边界值来确定。刚开始的时候老是用两个for循环嵌套，思维定式
 */

//求两个数组的中位数
//
function MedianTsa (&$arr1, &$arr2) {
    //设置一下长度
    //
    $len1 = sizeof($arr1);      //count()的别名
    $len2 = count($arr2);       //可选参数设置为1或者COUNT_RECURSIVE，即可递归统计整个数组
    $key = ($len1+$len2)/2;     //中位数的位置
    $save = array();            //存储数组
    $sta = 0;                   //计数器，用于$save数组指针的移动

    if ($len1 == 0 && $len2 == 0) {//两个空数组
        return -1 ;             //返回-1
    }
    #PHP 中除法可得到精确结果
    $i = 0;                     //计数器，用于$arr1数组
    $j = 0;                     //计数器，用于$arr2数组
    while ($sta <= $key) {      //判断是否到达了中位数的位置
        //先把小的数放进去
        //
        if ($i < $len1 && $j < $len2) {     //两个都在长度范围内
            if ($arr1[$i] <= $arr2[$j]) {       
                $save[$sta++] = $arr1[$i++];
            } else {
                $save[$sta++] = $arr2[$j++];
            }
        } elseif ($i == $len1) {            //$arr2是空表，或者$arr2更长
            $save[$sta++] = $arr2[$j++];
        } else{                             //$arr1是空表，或者$arr1更长
            $save[$sta++] = $arr1[$i++];
        }
    }

    if (($len1+$len2)%2 == 0) {     //偶数两个数的平均数是中位数
        return ($save[$key]+$save[$key-1])/2;
    } else {                        //奇数就是这个数本身
        return $save[$key];
    }
}

$arr1 = array(5,9);
$arr2 = array(1,2,7,9,15,20);
echo MedianTsa($arr1, $arr2)."\n";