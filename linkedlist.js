// 使用js 实现链表
// 完成以下的功能 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

function Node(value) {
    this.next = null;
    this.val = value; 
}
// 将整数转为链表
function createLinkedlist(num){
    num = num.toString();
    var head ;
    var cur; 
    head = new Node(num[num.length - 1 ]); 
    cur  = head; 
    for(var i = num.length - 2 ; i >= 0 ; i -- ) {
        cur.next = new Node(num[i]); 
        cur  = cur.next; 
    }
    return head; 
}
// 遍历链表 
function traverse(list){        
    while(list != null){
        console.log(list.val);
        list = list.next; 
    }
}
// return a new list 
function addTwoList(l1, l2 ) {
    // 将list转为整数 
    cur = l1; 
    var num1 = 0 , num2 = 0 ;
    for(var base = 1 ; cur != null ; cur = cur.next , base *= 10){
        num1 += cur.val*base; 
    }
    cur = l2;
    for(var base = 1 ; cur != null ; cur = cur.next , base *= 10){
        num2 += cur.val*base; 
    }
    sum = num1 + num2 ; 
    //创建链表
    return createLinkedlist(sum);
}
main = (arr1, arr2 )=>{
    l1 = createLinkedlist(342);
    l2 = createLinkedlist(465);
    traverse(addTwoList(l1,l2));
}
main([2,4,3],[5,6,4]);
