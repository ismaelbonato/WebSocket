var wSocket = new WebSocket('ws://localhost:1234');

wSocket.onopen = function(event) {
    alert('Connected');
}

wSocket.onclose = function(event) {
    alert('Finished');
}

wSocket.onmessage = function(event) {
    alert(event.value);
}

wSocket.onerror = function(event) {
    alert('This is a bug');
}

function send() {
    var txt = document.getElementById('txt');
    var val = txt.value;
    wSocket.send(val);
}
