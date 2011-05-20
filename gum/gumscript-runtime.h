"var GumMessageDispatcher, recv, send, _dispatcher;"
"var __bind = function(fn, me){ return function(){ return fn.apply(me, arguments); }; };"
"GumMessageDispatcher = (function() {"
  "function GumMessageDispatcher() {"
    "this.handleMessage = __bind(this.handleMessage, this);;    this.messages = [];"
    "this.callbacks = {};"
    "_setIncomingMessageCallback(this.handleMessage);"
  "}"
  "GumMessageDispatcher.prototype.registerCallback = function(type, callback) {"
    "this.callbacks[type] = callback;"
    "return this.dispatchMessages();"
  "};"
  "GumMessageDispatcher.prototype.handleMessage = function(rawMessage) {"
    "this.messages.push(JSON.parse(rawMessage));"
    "return this.dispatchMessages();"
  "};"
  "GumMessageDispatcher.prototype.dispatchMessages = function() {"
    "var message, pending, _i, _len;"
    "pending = this.messages.splice(0, this.messages.length);"
    "for (_i = 0, _len = pending.length; _i < _len; _i++) {"
      "message = pending[_i];"
      "this.dispatch(message);"
    "}"
  "};"
  "GumMessageDispatcher.prototype.dispatch = function(message) {"
    "var callback, handlerType;"
    "if (this.callbacks[message.type]) {"
      "handlerType = message.type;"
    "} else if (this.callbacks['*']) {"
      "handlerType = '*';"
    "} else {"
      "this.messages.push(message);"
      "return;"
    "}"
    "callback = this.callbacks[handlerType];"
    "delete this.callbacks[handlerType];"
    "callback(message);"
  "};"
  "return GumMessageDispatcher;"
"})();"
"_dispatcher = new GumMessageDispatcher();"
"send = function(payload) {"
  "var message;"
  "message = {"
    "type: 'send',"
    "payload: payload"
  "};"
  "return _send(JSON.stringify(message));"
"};"
"recv = function() {"
  "var callback, type;"
  "if (arguments.length === 1) {"
    "type = '*';"
    "callback = arguments[0];"
  "} else {"
    "type = arguments[0];"
    "callback = arguments[1];"
  "}"
  "return _dispatcher.registerCallback(type, callback);"
"};"