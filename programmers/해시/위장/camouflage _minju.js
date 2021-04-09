function solution(clothes) {
    let answer = 0;

    let wearingObj = new Object;

    console.log(wearingObj);
    wearingObj = clothes.reduce((wearingObj,curr)=>{
        if(wearingObj[curr[1]]) wearingObj[curr[1]]++;
        else wearingObj[curr[1]] = 1;
        return wearingObj;
    }, {});
    
    console.log(Object.values(wearingObj));
    answer = Object.values(wearingObj).reduce((acc,curr) => ( acc * (curr + 1) ), 1);
    //이전값 * (종류의 갯수 + 1(옷을 안입을 경우))


    
    return answer - 1 ;
}