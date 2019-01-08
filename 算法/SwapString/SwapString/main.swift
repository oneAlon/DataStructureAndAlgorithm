//
//  main.swift
//  SwapString
//
//  Created by xygj on 2019/1/4.
//  Copyright © 2019 OneAlon. All rights reserved.
//

import Foundation

func swapArray(_ array: inout Array<Any>, _ i: Int, _ j: Int) {
    let temp = array[i]
    array[i] = array[j]
    array[j] = temp
}


func reverseString() {
    let oriStr = "hello"
    var charArray = Array(oriStr)
    var i = 0
    var j = charArray.count - 1;
    while i < j {
        let temp = charArray[i]
        charArray[i] = charArray[j]
        charArray[j] = temp
        i = i + 1
        j = j - 1
    }
    
    print(charArray)
}

reverseString()

