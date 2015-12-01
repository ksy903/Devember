function calcValues(){
    var a = document.getElementById("one").value;
    var b = document.getElementById("two").value;
    var add = document.getElementById("add").checked;
    var sub = document.getElementById("sub").checked;
    var mul = document.getElementById("mul").checked;
    var div = document.getElementById("div").checked;
    var c = 0;
    if(add)
        c = +a + +b;
    else if(sub)
        c = +a - +b;
    else if(mul)
        c = +a * +b;
    else
        c = +a / +b;
    alert("Answer is " + c);
}

function storeData(){
    var data = document.getElementById("pass").value;
    localStorage.pass = data;
    document.getElementById("pass").value = "";
    alert('hu');
}

function retreiveData(){
    alert('Your password is ' + localStorage.pass);
}