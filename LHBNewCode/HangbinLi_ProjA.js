// Vertex shader program
var VSHADER_SOURCE =
    'attribute vec4 a_Position;\n' +
    'attribute vec4 a_Color;\n' +
    'varying vec4 v_Color;\n' +
    'uniform mat4 u_ModelMatrix;\n' +
    'void main() {\n' +
    '  gl_Position = u_ModelMatrix * a_Position;\n' +
    '  v_Color = a_Color;\n' +
    '}\n';

// Fragment shader program
// CCOL
var FSHADER_SOURCE =
    '#ifdef GL_ES\n' +
    'precision mediump float;\n' +
    '#endif GL_ES\n' +
    'varying vec4 v_Color;\n' +
    'void main() {\n' +
    '  gl_FragColor = v_Color;\n' +
    '}\n';

var g_initBirdPosX = -0.5;
var g_initBirdPosY = 0.3;
var g_initCloudPosX = -0.7;
var g_initCloudPosY = 0.75;
var g_autoBirdStepX = 0.0;
var g_autoAngleStep = [45.0, 60.0];
var g_autoColorChange = [0, 1]; // first element is flag for +/-

var g_dragBirdPosX = 0.0;
var g_dragBirdPosY = 0.0;

var g_keyWindSpeedX = 1.0;
var g_keyBirdPosY = 0.0;
var g_keyTreeLengthY = 1.0;
var g_clickMouseRorateStep = 0.0;

// extra credit
var g_cloudMove = 0.0;
var g_groundType = 0;
var g_treeNum = 1;
var g_treePosX = new Array();
var g_treePosY = new Array();
var g_treeScale = new Array();


var g_last = [Date.now(), Date.now()];
var canvas;

function main() {
    // Show help content on HTML
    writeHelp2Html(1);

    // inquery ground type
    var groundTypeSelect = document.getElementById('ground_type_select');
    groundTypeSelect.onchange = function() {
        g_groundType = (groundTypeSelect.selectedIndex);
    }
    var treeNumberSelect = document.getElementById('tree_num_select');
    treeNumberSelect.onchange = function() {
        document.getElementById("tree_num_span").innerHTML = treeNumberSelect.value;
        g_treeNum = treeNumberSelect.value;
    }

    // generate random position and scale for trees
    var i;
    for (i = 0; i < 10; i++) {
        g_treePosX[i] = (Math.random() - 0.5) * 1.4;
    }
    i = 0;
    while (i < 10) {
        ra = Math.random();
        if (ra > 0.8) {
            g_treePosY[i++] = -ra;
        }
    }
    i = 0;
    while (i < 10) {
        ra = Math.random();
        if (ra > 0.2 && ra < 0.7) {
            g_treeScale[i++] = ra;
        }
    }

    // Retrieve <canvas> element
    canvas = document.getElementById('webgl');

    // Get the rendering context for WebGL
    // var gl = getWebGLContext(canvas);
    var gl = canvas.getContext("experimental-webgl");
    if (!gl) {
        console.log('Failed to get the rendering context for WebGL');
        return;
    }

    // Initialize shaders
    if (!initShaders(gl, VSHADER_SOURCE, FSHADER_SOURCE)) {
        console.log('Failed to intialize shaders.');
        return;
    }

    // CCOL

    // Specify the color for clearing <canvas>
    gl.clearColor(0, 0, 0, 1);

    // Get storage location of u_ModelMatrix
    var u_ModelMatrix = gl.getUniformLocation(gl.program, 'u_ModelMatrix');
    if (!u_ModelMatrix) {
        console.log('Failed to get the storage location of u_ModelMatrix');
        return;
    }


    // Current rotation angle
    var currentAngle = [0.0, 0.0];
    // Model matrix
    var modelMatrix = new Matrix4();
    // Start drawing

    document.addEventListener('keydown', keydownHandler, false);
    canvas.addEventListener("mousedown", mousedownHandler, true);
    canvas.addEventListener("dragover", dragoverHandler, false);

    var tick = function() {
        // Write the positions of vertices to a vertex shader
        var n = initVertexBuffers(gl);
        if (n < 0) {
            console.log('Failed to set the positions of the vertices');
            return;
        }

        currentAngle = animate(currentAngle); // Update the rotation angle
        reAppear(currentAngle); // move entire bird
        draw(gl, n, currentAngle, modelMatrix, u_ModelMatrix); // Draw the triangle
        requestAnimationFrame(tick, canvas); // Request that the browser ?calls tick
    };
    tick();
}

function animate(angle) {
    // Calculate the elapsed time
    var now = Date.now();
    var elapsed = now - g_last[0];
    g_last[0] = now;
    // Update the current rotation angle (adjusted by the elapsed time)

    // angle[0] for wings, angle[1] for toes
    if (angle[0] > -10.0 && g_autoAngleStep[0] > 0) g_autoAngleStep[0] = -g_autoAngleStep[0];
    if (angle[0] < -65.0 && g_autoAngleStep[0] < 0) g_autoAngleStep[0] = -g_autoAngleStep[0];
    if (angle[1] > -10.0 && g_autoAngleStep[1] > 0) g_autoAngleStep[1] = -g_autoAngleStep[1];
    if (angle[1] < -65.0 && g_autoAngleStep[1] < 0) g_autoAngleStep[1] = -g_autoAngleStep[1];
    var new_angle = new Array();
    new_angle[0] = (angle[0] + (g_autoAngleStep[0] * elapsed) / 400.0 * g_keyWindSpeedX) % 360;
    new_angle[1] = (angle[1] + (g_autoAngleStep[1] * elapsed) / 1000.0) % 360;
    return new_angle;
}

function reAppear(currentAngle) {
    if (g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX >= 1.2) {
        g_autoBirdStepX = (-1.2 - g_initBirdPosX - g_dragBirdPosX) / g_keyWindSpeedX;
    } else {
        g_autoBirdStepX += 0.003;
    }
    if (g_initCloudPosX + g_cloudMove + (currentAngle[1] + 65) / 5000 >= 1.2) {
        g_initCloudPosX = -1.2 - g_cloudMove - (currentAngle[1] + 65) / 5000;
    }
}

function initVertexBuffers(gl) {

    var i = 5;

    // CCOL
    if (g_autoColorChange[0] == 0) {
        g_autoColorChange[1]++;
    } else {
        g_autoColorChange[1]--;
    }
    if (g_autoColorChange[1] == 0 || g_autoColorChange[1] == 299) {
        g_autoColorChange[0] = 1 - g_autoColorChange[0];
    }
    var autoColorChange = [0, (1 - g_autoColorChange[1] / 300), (1 - g_autoColorChange[1] / 1000)];

    var vertices = new Float32Array([

        // bird body (0-9)
        0.00, 0.00, 0.00, 1.00, 0.98, 0.981, 0.904,
        0.40, 0.10, 0.00, 1.00, 0.98, 0.855, 0.725,
        0.20, 0.22, 0.00, 1.00, 0.98, 0.855, 0.725, -0.06, 0.04, 0.00, 1.00, 0.98, 0.981, 0.804, -0.35, -0.05, 0.00, 1.00, 0.98, 0.981, 0.804, -0.45, -0.08, 0.00, 1.00, 0.98, 0.894, 0.710, -0.10, -0.20, 0.00, 1.00, 0.98, 0.981, 0.804,
        0.17, -0.22, 0.00, 1.00, 0.98, 0.981, 0.804,
        0.35, -0.05, 0.00, 1.00, 0.98, 0.855, 0.725,
        0.40, 0.10, 0.00, 1.00, 0.98, 0.855, 0.725,

        // bird foot leg (10-13)
        0.00, 0.00, 0.00, 1.00, 0.804, 0.522, 0.247,
        0.17, 0.00, 0.00, 1.00, 0.804, 0.522, 0.247,
        0.18, 0.04, 0.00, 1.00, 0.804, 0.522, 0.247,
        0.00, 0.035, 0.00, 1.00, 0.804, 0.522, 0.247,

        // bird foot toe (14-18)
        0.00, 0.01, 0.00, 1.00, 0.804, 0.522, 0.247,
        0.01, 0.00, 0.00, 1.00, 0.804, 0.522, 0.247,
        0.10, 0.03, 0.00, 1.00, 0.824, 0.412, 0.118,
        0.06, 0.04, 0.00, 1.00, 0.824, 0.412, 0.118,
        0.00, 0.04, 0.00, 1.00, 0.804, 0.522, 0.247,

        // bird near wing arm1&2 (19-22)
        0.00, 0.00, 0.00, 1.00, 0.98, 0.981, 0.804, -0.17, -0.17, 0.00, 1.00, 0.98, 0.981, 0.804, -0.08, -0.25, 0.00, 1.00, 1.0, 0.627, 0.478,
        0.12, -0.12, 0.00, 1.00, 1.0, 0.627, 0.478,

        // bird near wing arm3 (23-26)
        0.00, 0.00, 0.00, 1.00, 0.98, 0.981, 0.804, -0.22, -0.17, 0.00, 1.00, 0.98, 0.981, 0.804, -0.10, -0.18, 0.00, 1.00, 1.0, 0.627, 0.478,
        0.08, -0.10, 0.00, 1.00, 1.0, 0.627, 0.478,

        // bird far wing arm1&2 (27-30)
        0.00, 0.00, 0.00, 1.00, 0.98, 0.981, 0.804,
        0.17, 0.17, 0.00, 1.00, 0.98, 0.981, 0.804,
        0.08, 0.25, 0.00, 1.00, 1.0, 0.627, 0.478, -0.12, 0.12, 0.00, 1.00, 1.0, 0.627, 0.478,

        // bird far wing arm3 (31-34)
        0.00, 0.00, 0.00, 1.00, 0.98, 0.981, 0.804,
        0.22, 0.17, 0.00, 1.00, 0.98, 0.981, 0.804,
        0.12, 0.18, 0.00, 1.00, 1.0, 0.627, 0.478, -0.08, 0.10, 0.00, 1.00, 1.0, 0.627, 0.478,

        // bird mouse upper (35-38)
        0.00, 0.0, 0.00, 1.00, 0.698, 0.133, 0.133,
        0.3, 0.0, 0.00, 1.00, 0.698, 0.133, 0.133,
        0.27, 0.08, 0.00, 1.00, 0.502, 0.0, 0.0,
        0.0, 0.1, 0.00, 1.00, 0.502, 0.0, 0.0,

        // bird mouse lower(39-42)
        0.00, 0.00, 0.00, 1.00, 0.698, 0.133, 0.133,
        0.28, 0.03, 0.00, 1.00, 0.698, 0.133, 0.133,
        0.30, 0.10, 0.00, 1.00, 0.502, 0.0, 0.0,
        0.00, 0.10, 0.00, 1.00, 0.502, 0.0, 0.0,

        // tree trunk (43-46) center x=0.72
        0.02, 0.00, 0.00, 1.00, 0.63, 0.32, 0.18,
        0.02, 0.01, 0.00, 1.00, 0.63, 0.32, 0.18, -0.02, 0.01, 0.00, 1.00, 0.55, 0.27, 0.08, -0.02, 0.00, 0.00, 1.00, 0.55, 0.27, 0.08,

        // tree crown (47-51)
        0.04, 0.10, 0.00, 1.00, 0.00, 0.50, 0.00,
        0.00, 0.20, 0.00, 1.00, 0.41, 0.56, 0.13, -0.04, 0.10, 0.00, 1.00, 0.41, 0.56, 0.13, -0.13, 0.00, 0.00, 1.00, 0.41, 0.56, 0.13,
        0.13, 0.00, 0.00, 1.00, 0.41, 0.56, 0.13,

        // bird eye (52-55)
        0.02, 0.00, 0.00, 1.00, 0.467, 0.533, 0.6,
        0.02, 0.04, 0.00, 1.00, 0.440, 0.502, 0.565, -0.02, 0.04, 0.00, 1.00, 0.440, 0.502, 0.565, -0.02, 0.00, 0.00, 1.00, 0.467, 0.533, 0.6,

        // sky (56-59)
        -1.0, -1.0, 0.00, 1.00, 0.690, 0.878, 0.902, -1.0, 1.0, 0.00, 1.00, 0.275 * autoColorChange[1], 0.510 * autoColorChange[1], 0.706 * autoColorChange[1],
        1.0, 1.0, 0.00, 1.00, 0.275 * autoColorChange[1], 0.510 * autoColorChange[1], 0.706 * autoColorChange[1],
        1.0, -1.0, 0.00, 1.00, 0.690, 0.878, 0.902,

        // ground option 0 grassland (60-63)
        -1.0, -1.0, 0.00, 1.00, 0.565, 0.933, 0.565, -1.0, -0.8, 0.00, 1.00, 0.565, 0.933, 0.565,
        1.0, -0.8, 0.00, 1.00, 0.235, 0.702, 0.522,
        1.0, -1.0, 0.00, 1.00, 0.565, 0.933, 0.565,

        // cloud (64-75)
        0.0, 0.0, 0.00, 1.00, 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], 1.0 * autoColorChange[2],
        0.0, 0.4 * (0.6 + autoColorChange[1] / 5), 0.00, 1.00, 0.827 * autoColorChange[2], 0.827 * autoColorChange[2], 0.827 * autoColorChange[2], -0.1 * (0.9 + autoColorChange[1] / 5), 0.2 * (0.9 + autoColorChange[1] / 5), 0.00, 1.00, 0.827 * autoColorChange[2], 0.827 * autoColorChange[2], 0.827 * autoColorChange[2], -0.2, 0.2, 0.00, 1.00, 0.827 * autoColorChange[2], 0.827 * autoColorChange[2], 0.827 * autoColorChange[2], -0.3 * (1.2 - autoColorChange[1] / 4), 0.1, 0.00, 1.00, 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], -0.3 * (1.33 - autoColorChange[1] / 2), 0.0, 0.00, 1.00, 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], -0.2, -0.1, 0.00, 1.00, 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], 1.0 * autoColorChange[2],
        0.2, -0.1, 0.00, 1.00, 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], 1.0 * autoColorChange[2],
        0.3 * (1.5 - autoColorChange[1] / 2), 0.0, 0.00, 1.00, 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], 1.0 * autoColorChange[2],
        0.3 * (1.5 - autoColorChange[1] / 2), 0.1, 0.00, 1.00, 1.0 * autoColorChange[2], 1.0 * autoColorChange[2], 1.0 * autoColorChange[2],
        0.1, 0.4 * (0.6 + autoColorChange[1] / 5), 0.00, 1.00, 0.827 * autoColorChange[2], 0.827 * autoColorChange[2], 0.827 * autoColorChange[2],
        0.0, 0.4 * (0.6 + autoColorChange[1] / 5), 0.00, 1.00, 0.827 * autoColorChange[2], 0.827 * autoColorChange[2], 0.827 * autoColorChange[2],

        // ground option 1 soil (76-79)
        -1.0, -1.0, 0.00, 1.00, 0.855, 0.647, 0.125, -1.0, -0.8, 0.00, 1.00, 0.545, 0.271, 0.075,
        1.0, -0.8, 0.00, 1.00, 0.855, 0.647, 0.125,
        1.0, -1.0, 0.00, 1.00, 0.855, 0.647, 0.125,

        // ground option 2 water (80-83)
        -1.0, -1.0, 0.00, 1.00, 0.529, 0.807, 0.980, -1.0, -0.8, 0.00, 1.00, 0.529, 0.807, 0.980,
        1.0, -0.8, 0.00, 1.00, 0.678, 0.847, 0.910,
        1.0, -1.0, 0.00, 1.00, 0.529, 0.807, 0.980,

    ]);
    var n = 100; // The number of vertices

    // Create a buffer object
    var vertexBuffer = gl.createBuffer();
    if (!vertexBuffer) {
        console.log('Failed to create the buffer object');
        return -1;
    }

    // Bind the buffer object to target
    gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
    // Write date into the buffer object
    gl.bufferData(gl.ARRAY_BUFFER, vertices, gl.STATIC_DRAW);

    // CCOL
    var FSIZE = vertices.BYTES_PER_ELEMENT;

    // Assign the buffer object to a_Position variable
    var a_Position = gl.getAttribLocation(gl.program, 'a_Position');
    if (a_Position < 0) {
        console.log('Failed to get the storage location of a_Position');
        return -1;
    }

    // CCOL
    gl.vertexAttribPointer(a_Position, 4, gl.FLOAT, false, FSIZE * 7, 0);
    gl.enableVertexAttribArray(a_Position);
    var a_Color = gl.getAttribLocation(gl.program, 'a_Color');
    if (a_Color < 0) {
        console.log('Failed to get the storage location of a_Color');
        return -1;
    }
    gl.vertexAttribPointer(a_Color, 3, gl.FLOAT, false, FSIZE * 7, FSIZE * 4);
    gl.enableVertexAttribArray(a_Color); // Enable the assignment of the buffer object

    return n;
};

function draw(gl, n, currentAngle, modelMatrix, u_ModelMatrix) {
    // Clear <canvas>
    gl.clear(gl.COLOR_BUFFER_BIT);

    // calc tree rotate angle
    var treeRotateAngle = (1 - g_keyWindSpeedX) * 10;
    if (treeRotateAngle <= -5)
        treeRotateAngle = -5;
    else if (treeRotateAngle >= 5)
        treeRotateAngle = 5;

    // calc cloud translation
    g_cloudMove += (g_keyWindSpeedX - 1) / 500;

    // ------------- sky ----------------

    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.0, 0.0, 0.0);
    modelMatrix.scale(1, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 56, 4);

    modelMatrix = popMatrix();

    // ------------- ground ----------------

    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.0, 0.0, 0.0);
    modelMatrix.scale(1, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    if (g_groundType == 0) {
        gl.drawArrays(gl.TRIANGLE_FAN, 60, 4);
    } else if (g_groundType == 1) {
        gl.drawArrays(gl.TRIANGLE_FAN, 76, 4);
    } else {
        gl.drawArrays(gl.TRIANGLE_FAN, 80, 4);
    }

    modelMatrix = popMatrix();

    // ------------- cloud ----------------

    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(g_initCloudPosX + g_cloudMove + (currentAngle[1] + 65) / 5000, g_initCloudPosY, 0.0);
    modelMatrix.rotate(0, 0, 0, 1);
    modelMatrix.scale(0.5, 0.5, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 64, 12);

    modelMatrix = popMatrix();

    // ------------- big tree trunk ----------------
    if (g_groundType != 2) {

        pushMatrix(modelMatrix);

        modelMatrix.setTranslate(0.73, -0.95, 0.0);
        modelMatrix.rotate(treeRotateAngle / 40 + (currentAngle[1] + 37.5) / 450, 0, 0, 1);
        modelMatrix.scale(1, 1 * g_keyTreeLengthY, 1);
        gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
        gl.drawArrays(gl.TRIANGLE_FAN, 43, 4);

        for (var i = 0; i < 30; i++) {
            modelMatrix.translate(0.00, 0.01, 0.0);
            modelMatrix.rotate(treeRotateAngle / 40 + (currentAngle[1] + 37.5) / 450, 0, 0, 1);
            modelMatrix.scale(1, 1, 1);
            gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
            gl.drawArrays(gl.TRIANGLE_FAN, 43, 4);
        }

        // ------------- big tree crown ----------------

        modelMatrix.translate(0, 0, 0.0);
        modelMatrix.rotate(treeRotateAngle + (currentAngle[1] + 37.5) / 90, 0, 0, 1);
        modelMatrix.scale(1, 1.5, 1);
        gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
        gl.drawArrays(gl.TRIANGLE_FAN, 47, 5);

        modelMatrix.translate(0.0, 0.10, 0.0);
        modelMatrix.rotate(treeRotateAngle + (currentAngle[1] + 37.5) / 90, 0, 0, 1);
        modelMatrix.scale(0.8, 0.8, 1);
        gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
        gl.drawArrays(gl.TRIANGLE_FAN, 47, 5);

        modelMatrix.translate(0.0, 0.10, 0.0);
        modelMatrix.rotate(treeRotateAngle + (currentAngle[1] + 37.5) / 90, 0, 0, 1);
        modelMatrix.scale(0.8, 0.8, 1);
        gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
        gl.drawArrays(gl.TRIANGLE_FAN, 47, 5);

        modelMatrix.translate(0.0, 0.10, 0.0);
        modelMatrix.rotate(treeRotateAngle + (currentAngle[1] + 37.5) / 90, 0, 0, 1);
        modelMatrix.scale(0.8, 0.8, 1);
        gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
        gl.drawArrays(gl.TRIANGLE_FAN, 47, 5);

        modelMatrix = popMatrix();

        for (var j = 0; j < g_treeNum - 1; j++) {

            // ------------- random tree trunk ----------------
            pushMatrix(modelMatrix);

            modelMatrix.setTranslate(g_treePosX[j], g_treePosY[j], 0.0);
            modelMatrix.rotate(treeRotateAngle / 40 + (currentAngle[1] + 37.5) / 450, 0, 0, 1);
            modelMatrix.scale(1 * g_treeScale[j], 1 * g_treeScale[j], 1);
            gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
            gl.drawArrays(gl.TRIANGLE_FAN, 43, 4);

            for (var i = 0; i < 30; i++) {
                modelMatrix.translate(0.00, 0.01, 0.0);
                modelMatrix.rotate(treeRotateAngle / 40 + (currentAngle[1] + 37.5) / 450, 0, 0, 1);
                modelMatrix.scale(1, 1, 1);
                gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
                gl.drawArrays(gl.TRIANGLE_FAN, 43, 4);
            }

            // ------------- random tree crown ----------------

            modelMatrix.translate(0, 0, 0.0);
            modelMatrix.rotate(treeRotateAngle + (currentAngle[1] + 37.5) / 90, 0, 0, 1);
            modelMatrix.scale(1, 1.5 * g_keyTreeLengthY, 1);
            gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
            gl.drawArrays(gl.TRIANGLE_FAN, 47, 5);

            modelMatrix.translate(0.0, 0.10, 0.0);
            modelMatrix.rotate(treeRotateAngle + (currentAngle[1] + 37.5) / 90, 0, 0, 1);
            modelMatrix.scale(0.8, 0.8, 1);
            gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
            gl.drawArrays(gl.TRIANGLE_FAN, 47, 5);

            modelMatrix.translate(0.0, 0.10, 0.0);
            modelMatrix.rotate(treeRotateAngle + (currentAngle[1] + 37.5) / 90, 0, 0, 1);
            modelMatrix.scale(0.8, 0.8, 1);
            gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
            gl.drawArrays(gl.TRIANGLE_FAN, 47, 5);

            modelMatrix.translate(0.0, 0.10, 0.0);
            modelMatrix.rotate(treeRotateAngle + (currentAngle[1] + 37.5) / 90, 0, 0, 1);
            modelMatrix.scale(0.8, 0.8, 1);
            gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
            gl.drawArrays(gl.TRIANGLE_FAN, 47, 5);

            modelMatrix = popMatrix();

        }

    } //right bracket of if (g_groundType != 2)

    // ------------- bird mouse ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.15 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, +0.01 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(-20 + g_clickMouseRorateStep, 0, 0, 1);
    modelMatrix.scale(0.2, 0.2, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 35, 4);

    modelMatrix.translate(+0.01, -0.15, 0.0);
    modelMatrix.rotate(0 - g_clickMouseRorateStep, 0, 0, 1);
    modelMatrix.scale(1, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 39, 4);

    modelMatrix = popMatrix();

    // ------------- bird front foot toe 1 ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.065 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, -0.16 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(0 + currentAngle[1] / 2.8 - 30, 0, 0, 1);
    modelMatrix.scale(0.1, 0.2, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 10, 4);

    modelMatrix.translate(0.175, 0.0, 0.0);
    modelMatrix.rotate(-20, 0, 0, 1);
    modelMatrix.scale(2, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 14, 5);

    modelMatrix = popMatrix();

    // ------------- bird front foot toe 2 ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.065 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, -0.16 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(0 + currentAngle[1] / 2.8 - 60, 0, 0, 1);
    modelMatrix.scale(0.1, 0.2, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 10, 4);

    modelMatrix.translate(0.175, 0.0, 0.0);
    modelMatrix.rotate(-20, 0, 0, 1);
    modelMatrix.scale(2, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 14, 5);

    modelMatrix = popMatrix();

    // ------------- bird front foot toe 3 ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.065 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, -0.16 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(0 - currentAngle[1] / 2.8 - 120, 0, 0, 1);
    modelMatrix.scale(0.1, 0.2, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 10, 4);

    modelMatrix.translate(0.175, 0.0, 0.0);
    modelMatrix.rotate(-20, 0, 0, 1);
    modelMatrix.scale(1, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 14, 5);

    modelMatrix = popMatrix();

    // ------------- bird back foot toe 1 ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.022 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, -0.16 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(0 + currentAngle[1] / 2.8 - 30, 0, 0, 1);
    modelMatrix.scale(0.1, 0.2, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 10, 4);

    modelMatrix.translate(0.175, 0.0, 0.0);
    modelMatrix.rotate(-20, 0, 0, 1);
    modelMatrix.scale(2, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 14, 5);

    modelMatrix = popMatrix();

    // ------------- bird back foot toe 2 ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.022 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, -0.16 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(0 + currentAngle[1] / 2.8 - 60, 0, 0, 1);
    modelMatrix.scale(0.1, 0.2, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 10, 4);

    modelMatrix.translate(0.175, 0.0, 0.0);
    modelMatrix.rotate(-20, 0, 0, 1);
    modelMatrix.scale(2, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 14, 5);

    modelMatrix = popMatrix();

    // ------------- bird back foot toe 3 ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.022 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, -0.16 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(0 - currentAngle[1] / 2.8 - 120, 0, 0, 1);
    modelMatrix.scale(0.1, 0.2, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 10, 4);

    modelMatrix.translate(0.175, 0.0, 0.0);
    modelMatrix.rotate(-20, 0, 0, 1);
    modelMatrix.scale(1, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 14, 5);

    modelMatrix = popMatrix();

    // ------------- bird far wing ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.10 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, 0.00 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(5 - currentAngle[0] / 2, 0, 0, 1);
    modelMatrix.scale(0.5, 0.5, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 27, 4);

    modelMatrix.translate(0.18, 0.17, 0.0);
    modelMatrix.rotate(5, 0, 0, 1);
    modelMatrix.scale(0.7, 0.7, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 27, 4);

    modelMatrix.translate(0.18, 0.177, 0.0);
    modelMatrix.rotate(10, 0, 0, 1);
    modelMatrix.scale(1, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 31, 4);

    modelMatrix = popMatrix();

    // ------------- bird body and leg ---------------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.0 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, 0.0 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.scale(0.45, 0.6, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 0, 10);

    modelMatrix.translate(0.15, -0.22, 0.0);
    modelMatrix.rotate(-90, 0, 0, 1);
    modelMatrix.scale(0.3, 0.4, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 10, 4);

    modelMatrix.translate(-0.024, -0.25, 0.0);
    modelMatrix.rotate(0, 0, 0, 1);
    modelMatrix.scale(1, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 10, 4);

    modelMatrix = popMatrix();

    // ------------- bird eye ----------------

    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.125 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, 0.03 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(45, 0, 0, 1);
    modelMatrix.scale(0.25, 0.32, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 52, 4);

    modelMatrix = popMatrix();

    // ------------- bird near wing ----------------
    pushMatrix(modelMatrix);

    modelMatrix.setTranslate(0.07 + g_initBirdPosX + g_autoBirdStepX * g_keyWindSpeedX + g_dragBirdPosX, 0.02 + g_dragBirdPosY + g_initBirdPosY + g_keyBirdPosY, 0.0);
    modelMatrix.rotate(-60 + currentAngle[0], 0, 0, 1);
    modelMatrix.scale(0.4, 0.7, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 19, 4);

    modelMatrix.translate(-0.18, -0.175, 0.0);
    modelMatrix.rotate(-5, 0, 0, 1);
    modelMatrix.scale(0.88, 0.6, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 19, 4);

    modelMatrix.translate(-0.17, -0.177, 0.0);
    modelMatrix.rotate(3, 0, 0, 1);
    modelMatrix.scale(1, 1, 1);
    gl.uniformMatrix4fv(u_ModelMatrix, false, modelMatrix.elements);
    gl.drawArrays(gl.TRIANGLE_FAN, 23, 4);

    modelMatrix = popMatrix();

};

// Last time that this function was called:  (used for animation timing)

function dragoverHandler(event) {
    var x = event.clientX;
    var y = event.clientY;
    var rect = event.target.getBoundingClientRect();
    g_dragBirdPosX = ((x - rect.left) - canvas.width / 2) / (canvas.width / 2);
    g_dragBirdPosY = (canvas.height / 2 - (y - rect.top)) / (canvas.height / 2);
}

function keydownHandler(event) {
    var e = event.keyCode;

    if (e == 37) { // left arrow key
        changeWindSpeed(-1);
    }

    if (e == 39) { // right arrow key
        changeWindSpeed(1);
    }

    if (e == 191) { // '/' key
        changeWindSpeed(0);
    }

    if (e == 38) { // up arrow key
        g_keyTreeLengthY += 0.01;
        if (g_keyTreeLengthY >= 1.5) {
            g_keyTreeLengthY = 1.5;
        }
        g_keyBirdPosY += 0.005;
        if (g_keyBirdPosY >= 0.5) {
            g_keyBirdPosY = 0.5;
        }
    }

    if (e == 40) { // down arrow key
        g_keyTreeLengthY -= 0.01;
        if (g_keyTreeLengthY <= 0.5) {
            g_keyTreeLengthY = 0.5;
        }
        g_keyBirdPosY -= 0.005;
        if (g_keyBirdPosY <= -0.7) {
            g_keyBirdPosY = -0.7;
        }
    }

    if (e == 112) { // F1 key
        writeHelp2Html(1);
    }

    if (e == 27) { // Esc key
        writeHelp2Html(0);
    }
}

function mousedownHandler(event) {
    g_clickMouseRorateStep === 0 ? g_clickMouseRorateStep = -20 : g_clickMouseRorateStep = 0;
}

function changeWindSpeed(boolSpeed) {
    if (boolSpeed == 1) {
        g_keyWindSpeedX += 0.05;
        if (g_keyWindSpeedX >= 4.0) {
            g_keyWindSpeedX = 4.0;
        }
    } else if (boolSpeed == -1) {
        g_keyWindSpeedX -= 0.05;
        if (g_keyWindSpeedX <= 0.5) {
            g_keyWindSpeedX = 0.5;
        }
    } else if (boolSpeed == 0)
        g_keyWindSpeedX = 1.0;
    writeWindSpeed2Html();
}

function writeWindSpeed2Html() {
    document.getElementById("wind_speed_div").innerHTML = "Wind Speed: " + (g_keyWindSpeedX - 1).toFixed(2).toString();
}

function writeHelp2Html(boolHelp) {
    if (boolHelp == 1) {
        var helpContent;
        if (document.getElementById("help_content_div").innerHTML == "") {
            helpContent = "Mouse Left Click: Bird's mouse will close or open. <p>" +
                "Mouse Drag: Bird will follow mouse's position when dragging. <p>" +
                "Left / Right Arrow Key: Wind affects bird's speed and tree. <p>" +
                "Up / Down Arrow Key: Right tree's height changes, bird flies higher.<p>" +
                "'/' Key: Reset wind speed, F1 - Show Help, Esc - Hide Help <p>" +
                "Animated elements include: <p>" +
                "1. Bird's wings waving. <p>" +
                "2. Bird's claws clenching. <p>" +
                "3. Bird translating. <p>" +
                "4. Tree swinging. <p>" +
                "extra 1. Webpage controls of wind speed, tree number, ground type. <p>" +
                "extra 2. Sky color changes smoothly. <p>" +
                "extra 3. Cloud shape changes (not scaling). <p>";
            document.getElementById("help_content_div").innerHTML = helpContent;
        }
    } else if (boolHelp == 0) {
        document.getElementById("help_content_div").innerHTML = "";
    }
}