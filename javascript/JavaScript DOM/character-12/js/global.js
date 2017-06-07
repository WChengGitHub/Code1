function addLoadEvent(func){
	var oldonload=window.onload;
	if(typeof oldonload!='function'){
		window.onload=func;
	}else{
		window.onload=function(){
			oldonload();
			func();
		}
	}
}

function insertAfter(newElement,targetElement){
	var parent=targetElement.parentNode;
	if(parent.lastChild==targetElement){
		parent.appendChild(newElement);
	}else{
		parent.insertBefore(newElement,targetElement.nextSibling);
	}
}

function addClass(element,value){
	if(!element.className){
		element.className=value;
	}else{
		var newClassName=element.className;
		newClassName+=" ";
		newClassName+=value;
		element.className=newClassName;
	}
}

function hightlightPage(){
	if(!document.getElementsByTagName)
		return false;
	
	var headers=document.getElementsByTagName("header");
	if(headers.length==0){
		return false;
	}
	
	var navs=headers[0].getElementsByTagName("nav");
	if(navs.length==0){
		return false;
	}
	
	var links=navs[0].getElementsByTagName("a");
	var linkurl;
	for(var i=0;i<links.length;i++){
		linkurl=links[i].getAttribute("href");
		if(window.location.href.indexOf(linkurl)!=-1){
			addClass(links[i],"here");
			var linktext=links[i].lastChild.nodeValue.toLowerCase();
			document.body.setAttribute("id",linktext);
		}
	}
}

function moveElement(ID,final_x,final_y,interval){
	if(!document.getElementById)
		return false;
	if(!document.getElementById(ID))
		return false;
	
	var element=document.getElementById(ID);
	if(element.movement){
		clearTimeout(element.movement);
	}
	
	if(!element.style.left)
	{
		element.style.left="0px";
	}
	if(!element.style.top)
	{
		element.style.top="0px";
	}
	
	var x=parseInt(element.style.left);
	var y=parseInt(element.style.top);
	
	if(x==final_x&&y==final_y){
		return true;
	}
	
	if(x<final_x){
		var dist=Math.ceil((final_x-x)/10);
		x=x+dist;
	}
	if(x>final_x){
		var dist=Math.ceil((x-final_x)/10);
		x=x-dist;
	}
	if(y<final_y){
		var dist=Math.ceil((final_y-y)/10);
		y=y+dist;
	}
	if(y>final_y){
		var dist=Math.ceil((y-final_y)/10);
		y=y-dist;
	}
	
	element.style.left=x+"px";
	element.style.top=y+"px";
	
	element.movement=setTimeout("moveElement('"+ID+"',"+final_x+","+final_y+","+interval+")",interval);
}

function prepareSlideshow(){
	if(!document.getElementById)
		return false;
	if(!document.getElementsByTagName)
		return false;
	if(!document.getElementById("intro"))
		return false;
	var div=document.createElement("div");
	div.setAttribute("id","slideshow");
	
	var img=document.createElement("img");
	img.setAttribute("id","preview");
	img.setAttribute("src","images/slideshow.gif");
	img.setAttribute("alt","a glimpse of what awaits you");
	
	div.appendChild(img);
	
	var para=document.getElementById("intro");
	insertAfter(div,para);
	
	var links=document.getElementsByTagName("a");
	for(var i=0;i<links.length;i++){
		var href=links[i].getAttribute("href");
		if(href.indexOf("index.html")!=-1){
			links[i].onmouseover=function(){
				moveElement("preview","0","0",5);
			}
		}else if(href.indexOf("about.html")!=-1){
			links[i].onmouseover=function(){
				moveElement("preview","-150","0",5);
			}
		}else if(href.indexOf("photos.html")!=-1){
			links[i].onmouseover=function(){
				moveElement("preview","-300","0",5);
			}
		}else if(href.indexOf("live.html")!=-1){
			links[i].onmouseover=function(){
				moveElement("preview","-450","0",5);
			}
		}else if(href.indexOf("contact.html")!=-1){
			links[i].onmouseover=function(){
				moveElement("preview","-600","0",5);
			}
		}
	}
	
	var img1=document.createElement("img");
	img1.setAttribute("id","frame");
	img1.setAttribute("src","images/frame.gif");
	slideshow.appendChild(img1);
}
function showSection(id){
	var sections=document.getElementsByTagName("section");
	for(var i=0;i<sections.length;i++){
		if(sections[i].getAttribute("id")==id){
			sections[i].style.display="block";
		}else{
			sections[i].style.display="none";
		}
	}
	return false;
}
function prepareInternalnav(){
	if(!document.getElementById)
		return false;
	if(!document.getElementsByTagName)
		return false;
	
	var articles=document.getElementsByTagName("article");
	if(articles.length==0)
		return false;
	
	var navs=articles[0].getElementsByTagName("nav");
	if(navs.length==0)
		return false;
	
	var links=navs[0].getElementsByTagName("a");
	for(var i=0;i<links.length;i++){
		var href=links[i].getAttribute("href");
		var array=href.split("#");
		var elementId=array[1];
		if(!document.getElementById(elementId))
			continue;
		var element=document.getElementById(elementId);
		element.style.display="none";
		links[i].destination=elementId;
		links[i].onclick=function(){
			showSection(this.destination);
			return false;
		}                                                                                                                                                   
		
	}
}
function preparePlaceholder(){
	if(!document.createElement)
		return false;
	if(!document.createTextNode)
		return false;
	if(!document.getElementById)
		return false;
	if(!document.getElementById("imagegallery"))
		return false;
	var para=document.createElement("p");
	para.setAttribute("id","description");
	
	var txt=document.createTextNode("choose a picture");
	para.appendChild(txt);
	
	var imagegallery=document.getElementById("imagegallery");
	insertAfter(para,imagegallery);
	
	var img=document.createElement("img");
	img.setAttribute("id","placeholder");
	img.setAttribute("src","images/placeholder.gif");
	img.setAttribute("alt","");
	insertAfter(img,para);
	return true;
	
}
function showPic(whicPic){
	
	if(!document.getElementById)
		return false;
	if(!document.getElementById("placeholder"))
		return false;
	if(!document.getElementById("description"))
		return false;
		
	var href=whicPic.getAttribute("href");
	var placeholder=document.getElementById("placeholder");
	placeholder.setAttribute("src",href);
	
	var txt;
	if(whicPic.getAttribute("title")){
		txt=whicPic.getAttribute("title");
	}else{
		txt="";
	}
	
	var description=document.getElementById("description");
	description.firstChild.nodeValue=txt;
	return false;
}
function prepareOnclick(){
	if(!document.getElementById("imagegallery"))
		return false;
	var imagegallery=document.getElementById("imagegallery");
	var links=imagegallery.getElementsByTagName("a");
	for(var i=0;i<links.length;i++){
		links[i].onclick=function(){
			showPic(this);
			return false;
		}
	}
}

function stripeTables(){
	if(!document.getElementsByTagName)
		return false;
	var tables=document.getElementsByTagName("table");
	for(var i=0;i<tables.length;i++){
		var odd=false;
		var rows=tables[i].getElementsByTagName("tr");
		for(var j=0;j<rows.length;j++){
			if(odd==true){
				addClass(rows[j],"odd");
				odd=false;
			}else if(odd==false){
				odd=true;
			}
		}
	}
}

function highlightRows(){
	if(!document.getElementsByTagName)
		return false;
	var trs=document.getElementsByTagName("tr");
	for(var i=0;i<trs.length;i++){
		trs[i].oldClassName=trs[i].className;
		trs[i].onmouseover=function(){
			addClass(this,"highlight");
		}
		trs[i].onmouseout=function(){
			this.className=this.oldClassName;
		}
	}
}

function displayAbbreviations(){
	if(!document.getElementsByTagName)
		return false;
	if(!document.createElement)
		return false;
	if(!document.createTextNode)
		return false;
	
	var abbrs=document.getElementsByTagName("abbr");
	if(abbrs.length<1)
		return false;
	
	var defs=new Array();
	for(var i=0;i<abbrs.length;i++){
		var current_abbr=abbrs[i];
		if(current_abbr.childNodes.length<1)
			continue;
		var key=current_abbr.lastChild.nodeValue;
		var value=current_abbr.getAttribute("title");
		defs[key]=value;
	}
	
	var dl=document.createElement("dl");
	for(key in defs){
		var dt=document.createElement("dt");
		var dt_text=document.createTextNode(key);
		dt.appendChild(dt_text);
		
		var dd=document.createElement("dd");
		var dd_text=document.createTextNode(defs[key]);
		dd.appendChild(dd_text);
		
		dl.appendChild(dt);
		dl.appendChild(dd);
	}
	
	if(dl.childNodes.length<1)
		return false;
	var h3=document.createElement("h3");
	var h3_text=document.createTextNode("Abbreviations");
	h3.appendChild(h3_text);
	
	var articles=document.getElementsByTagName("article");
	if(articles.length<1)
		return false;
	articles[0].appendChild(h3);
	articles[0].appendChild(dl);
}
function focusLabel(){
	if(!document.getElementsByTagName)
		return false;
	if(!document.getElementById)
		return false;
	var labels=document.getElementsByTagName("label");
	for(var i=0;i<labels.length;i++){
		var id=labels[i].getAttribute("for");
		if(!id)
			continue;
		if(!document.getElementById(id))
			continue;
	    labels[i].element=document.getElementById(id);
		labels[i].onclick=function(){
			this.element.focus();
		}
	}
}
function resetFields(whichform){
	if(Modernizr.input.placeholder)return;
	for(var i=0;i<whichform.elements.length;i++){
		var element=whichform.elements[i];
		if(element.type=="submit")
			continue;
		var check=element.placeholder||element.getAttribute("placeholder");
		if(!check)
			continue;
		element.onfocus=function(){
			var text=this.placeholder||this.getAttribute("placeholder");
			if(text==this.value){
				this.value="";
				this.className="";
			}
		}
		element.onblur=function(){
			var text=this.placeholder||this.getAttribute("placeholder");
			if(this.value==""){
				this.value=text;
				this.className="placeholder";
			}
		}
		element.onblur();
	}
	
}
function prepareForms(){
	for(var i=0;i<document.forms.length;i++){
		resetFields(document.forms[i]);
		document.forms[i].onsubmit=function(){
			if(validateForm(this)){
				var article=document.getElementsByTagName("article")[0];
				if(submitFormWithAjax(this,article))
					return false;
				return true;
			}
			else{
				return false;
			}
		}
	}
}
function isFilled(field){
	if(field.value.replace(' ','').length<1)
		return false;
	if(field.value==field.getAttribute("placeholder"))
		return false;
	return true;
}
function isEmail(field){
	if(field.value.indexOf('@')==-1||field.value.indexOf('.')==-1)
		return false;
	return true;
}
function validateForm(whichform){
	for(var i=0;i<whichform.elements.length;i++){
		var element=whichform.elements[i];
		if(element.getAttribute("required")=="required"){
			if(!isFilled(element)){
				alert("Please fill in the "+element.name+" field.");
			return false;}
			
		}
		if(element.getAttribute("type")=="email"){
			if(!isEmail(element)){
				alert("The "+element.name+" field must be a valid email address.");
			return false;
			}
		}
	}
	return true;
}
function getHTTPObject(){
	if(typeof XMLHttpRequest=="undefined")
		XMLHttpRequest=function(){
			try{
				return new ActiveXObject("Msxml2.XMLHTTP.6.0");
			}catch(e){}
			try{
				return new ActiveXObject("Msxml2.XMLHTTP.3.0");
			}catch(e){}
			try{
				return new ActiveXObject("Msxml2.XMLHTTP");
			}catch(e){}
			return false;
		}
		return new XMLHttpRequest();
}

function displayAjaxLoading(element){
	while(element.hasChildNodes()){
		element.removeChild(element.lastChild);
	}
	var img=document.createElement("img");
	img.setAttribute("src","images/loading.gif");
	img.setAttribute("alt","loading...");
	element.appendChild(img);
}

function submitFormWithAjax(whichform,thetarget){
	var dataParts=[];
	for(var i=1;i<whichform.elements.length;i++){
		var element=whichform.elements[i];
		if(element.type=="submit")
			continue;
		dataParts[i-1]=element.name+"="+encodeURIComponent(element.value);
	}
	data=dataParts.join('&');
	var request=getHTTPObject();
	if(request){
		displayAjaxLoading(thetarget);
		request.open("post",whichform.action,true);
		request.setRequestHeader("Content-type","application/x-www-form-urlencoded");
		request.onreadystatechange=function(){
			if(request.readyState=="4"&&(request.status=="200"||request.status=="0")){
				var matches=request.responseText.match(/<article>([\s\S]+)<\/article>/);
				if(matches.length<1)
					thetarget.innerHTML="<p>Oops,there was an error. Sorry.</p>";
				else{
					thetarget.innerHTML=matches[1];
				}
			}
		}
		request.send(data);
		return true;
	}
	else{
		return false;
	}
}

addLoadEvent(hightlightPage);
addLoadEvent(prepareSlideshow);
addLoadEvent(prepareInternalnav);
addLoadEvent(preparePlaceholder);
addLoadEvent(prepareOnclick);
addLoadEvent(stripeTables);
addLoadEvent(highlightRows);
addLoadEvent(displayAbbreviations);
addLoadEvent(focusLabel);
addLoadEvent(prepareForms);