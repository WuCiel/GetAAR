package com.example.aartest;

/**
 * Created by elevoc on 2017/8/24.
 */

public class HelloWorld {

    static{
        System.loadLibrary("test");
    }

    private String ans="普通成员变量";
    public static String ans1="静态成员变量";

    public static String getStaticAns(){
        return ans1;
    }

    public native String testGetString();
}
