window.onload=function()
{
	preparePlaceholder();
	showGallery();
}
function showGallery()
{
	if(!document.getElementById)
		return false;
	if(!document.getElementsByTagName)
		return false;
	if(!document.getElementById("gallery"))
		return false;
	var gallery=document.getElementById("gallery");
	var links=gallery.getElementsByTagName("a");
	for(var i=0;i<links.length;i++)
	{
		links[i].onclick=function()
		{
			return !showPic(this);
		}
	}
}
function showPic(pic)
{
	if(!document.getElementById("description"))
		return false;
	var source=pic.getAttribute("href");
	var text=pic.getAttribute("title")?pic.getAttribute("title"):"";
	var myImg=document.getElementById("myImg");
	myImg.setAttribute("src",source);
	if(document.getElementById("description"))
	{
	var myDescription=document.getElementById("description");
	myDescription.firstChild.nodeValue=text;
	}
	return true;
}
function insertAfter(newElement,targetElement)
{
	var parent=targetElement.parentNode;
	if(parent.lastChild==targetElement)
		parent.appendChild(newElement);
	else
	{
		var brother=targetElement.nextSibling;
		parent.insertBefore(newElement,brother);
	}
}
function preparePlaceholder()
{
	if(!document.createElement)
		return false;
	if(!document.getElementById)
		return false;
	if(!document.getElementById("gallery"))
		return false;
	if(!document.createTextNode)
		return false;
	var gallery=document.getElementById("gallery");
	var img=document.createElement("img");
	img.setAttribute("id","myImg");
	var para=document.createElement("p");
	para.setAttribute("id","description");
	var text=document.createTextNode("choose a picture");
	para.appendChild(text);
	insertAfter(img,gallery);
	insertAfter(para,img);
	
}
