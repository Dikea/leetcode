博弈游戏，需要决定现在石头的数目是否是必胜态或者是必败态。
当n = 4的时候是必败态，因为n = 5, 6, 7都能够拿掉三个以内的石头变成4，所以都属于必胜态，而n = 8不能到达4，所以是必败态，则n = 9, 10, 12都是必胜态。
所以，当n % 4 == 0时必胜，否则必败。