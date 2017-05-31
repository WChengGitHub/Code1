function prepareSlideshow(){

	if(!document.getElementById)
		return false;
	if(!document.getElementsByTagName)
		return false;
	/*if(!document.getElementById("preview"))
		return false;
	*/
	if(!document.getElementById("linkedList"))
		return false;
	
	var div=document.createElement("div");
	div.setAttribute("id","slideshow");
	
	var img=document.createElement("img");
	img.setAttribute("id","preview");
	img.setAttribute("src","images/sky.jpg");
	img.setAttribute("alt","building blocks of web design");
	
	div.appendChild(img);
	/*var preview=document.getElementById("preview");
	preview.style.position="absolute";
	/*preview.style.left="0px";
	preview.style.top="0px";*/
	
	var linkedList=document.getElementById("linkedList");
	insertAfter(div,linkedList);
	
	var links=linkedList.getElementsByTagName("a");
	
	links[0].onmouseover=function(){
		moveElementById("preview",-100,0,10);
	}
	links[1].onmouseover=function(){
		moveElementById("preview",-200,0,10);
	}
	links[2].onmouseover=function(){
		moveElementById("preview",-300,0,10);
	}
}
addLoadEvent(prepareSlideshow);