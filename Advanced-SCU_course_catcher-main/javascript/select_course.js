let course_name=arguments[0];
let enties=document.getElementsByClassName("samexqh");
for(var i=0; i<enties.length; i++){
    let node=enties[i];
    if(node.childNodes[2].innerHTML.indexOf(course_name)!=-1){
        node.childNodes[0].childNodes[0].click();
        return "yes";
    }
}
return "no";