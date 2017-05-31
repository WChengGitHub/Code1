window.onload=function(){
	getNewContent();
}

function getNewContent(){
	var request=getHTTPObject();
	if(request){
	request.open("get","example.txt",true);
	request.onreadystatechange=function()
	{
		if(request.readyState==4)
		{
			var newDiv=document.getElementById("new");
			var para=document.createElement("p");
			var txt=document.createTextNode(request.responseText);
			newDiv.appendChild(para);
			para.appendChild(txt);
		}
	}
	request.send(null);
	}else{
		alert('Sorry,you browser doesn\'t support XMLHttpRequest');
	}
}