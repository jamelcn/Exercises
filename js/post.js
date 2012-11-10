function post (url, data, callbackfunc) {
	// body...
}

var XMLHttpReq;
function createXMLHttpRequest () {
	try {
		XMLHttpReq = new ActiveXObject("Msxml2.XMLHTTP");
	} catch(E) {
		try {
			XMLHttpReq = new ActiveXObject("Microsoft.XMLHTTP");
		} catch(E) {
			XMLHttpReq = new XMLHttpRequest();
		}
	}
}

function sendAjaxRequest (method, url, name) {
		createXMLHttpRequest();
	if (method === "post"){ 	// post
		var para = "Name=" + encodeURI(name);
		XMLHttpReq.open("post", url, true);
		XMLHttpReq.onreadystatechange = processResponse;
		// Post required
		XMLHttpReq.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;");
		XMLHttpReq.send(para);
	} else if (method === "get") {
		var url = url + "?Name=" + encodeURI(name);
		XMLHttpReq.open("get", url, true);
		XMLHttpReq.send(NULL);
	};
}

function processResponse () {
	if (XMLHttpReq.readystate == 4) {
		if (XMLHttpReq.status == 200) {
			var text = XMLHttpReq.responseText;
			text = window.decodeURI(text);
			var cp = document.getElementById("cp");
			cp.innerHTML = "";
			var values = text.split("|");
			for (var i = 0; i < values.length; i++) {
				var temp = document.createElement("option");
				temp.text = values[i];
				temp.value = values[i];
				cp.options.add(temp)
			};
	};
}


