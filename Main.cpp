<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>Sound Advice</title>

  <style>
    * {
      box-sizing: border-box;
      margin: 0;
      padding: 0;
      font-family: Arial, sans-serif;
    }

    body {
      background-color: #121212;
      color: white;
      min-height: 100vh;
    }

    /* Top navigation */
    header {
      background-color: #1d1d1d;
      padding: 20px 40px;
      border-bottom: 1px solid #333;
    }

    header h1 {
      font-size: 26px;
    }

    header p {
      color: #aaa;
      margin-top: 5px;
    }

    /* Main page layout */
    main {
      display: flex;
      gap: 30px;
      max-width: 1100px;
      margin: 50px auto;
      padding: 20px;
    }

    .panel {
      background-color: #1d1d1d;
      border: 1px solid #333;
      border-radius: 12px;
      padding: 25px;
      flex: 1;
    }

    .panel h2 {
      margin-bottom: 8px;
    }

    .description {
      color: #aaa;
      margin-bottom: 25px;
    }

    /* Upload area */
    .upload-box {
      border: 2px dashed #555;
      border-radius: 12px;
      height: 250px;

      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;

      text-align: center;
      cursor: pointer;
      transition: 0.2s;
    }

    .upload-box:hover {
      border-color: #8b5cf6;
      background-color: #252525;
    }

    .upload-icon {
      font-size: 50px;
      margin-bottom: 15px;
    }

    .upload-button {
      background-color: #8b5cf6;
      color: white;

      padding: 12px 22px;
      border: none;
      border-radius: 8px;

      font-size: 16px;
      cursor: pointer;
      margin-top: 15px;
    }

    .upload-button:hover {
      background-color: #7c3aed;
    }

    #fileInput {
      display: none;
    }

    #uploadStatus {
      margin-top: 15px;
      color: #aaa;
    }

    /* Player */
    .song-card {
      background-color: #252525;
      border-radius: 12px;
      padding: 20px;
    }

    .song-info {
      display: flex;
      align-items: center;
      gap: 15px;
      margin-bottom: 25px;
    }

    .album-art {
      width: 70px;
      height: 70px;

      background-color: #333;
      border-radius: 10px;

      display: flex;
      justify-content: center;
      align-items: center;

      font-size: 30px;
    }

    .song-name {
      font-size: 18px;
      font-weight: bold;
    }

    .song-type {
      color: #aaa;
      margin-top: 5px;
      font-size: 14px;
    }

    audio {
      width: 100%;
    }

    .status {
      display: inline-block;
      background-color: #333;
      color: #aaa;

      padding: 6px 12px;
      border-radius: 20px;

      font-size: 13px;
      margin-top: 20px;
    }

    .ready {
      background-color: #204c35;
      color: #6ee7a8;
    }

    /* Responsive */
    @media (max-width: 750px) {
      main {
        flex-direction: column;
      }
    }
  </style>
</head>

<body>

<header>
  <h1>Sound Advice</h1>
  <p>Upload your music and start listening.</p>
</header>

<main>

  <!-- UPLOAD SECTION -->
  <section class="panel">

    <h2>Add a Song</h2>

    <p class="description">
      Upload an audio file from your computer.
    </p>

    <label class="upload-box" for="fileInput">

      <div class="upload-icon">♫</div>

      <strong>Upload Song</strong>

      <p style="color:#aaa; margin-top:8px;">
        Choose an audio file from your computer
      </p>

      <span class="upload-button">
        Choose File
      </span>

    </label>

    <input
      type="file"
      id="fileInput"
      accept="audio/*"
    >

    <p id="uploadStatus">
      No song uploaded yet.
    </p>

  </section>


  <!-- PLAYER SECTION -->
  <section class="panel">

    <h2>Now Playing</h2>

    <p class="description">
      Your uploaded song will appear here.
    </p>

    <div class="song-card">

      <div class="song-info">

        <div class="album-art">
          ♪
        </div>

        <div>

          <div
            class="song-name"
            id="songName"
          >
            No song selected
          </div>

          <div
            class="song-type"
            id="songType"
          >
            Upload a file to begin
          </div>

        </div>

      </div>

      <audio
        id="audioPlayer"
        controls
      ></audio>

      <div
        id="playerStatus"
        class="status"
      >
        Waiting for song
      </div>

    </div>

  </section>

</main>


<script>

  // Get the HTML elements we need
  const fileInput =
    document.getElementById("fileInput");

  const audioPlayer =
    document.getElementById("audioPlayer");

  const songName =
    document.getElementById("songName");

  const songType =
    document.getElementById("songType");

  const uploadStatus =
    document.getElementById("uploadStatus");

  const playerStatus =
    document.getElementById("playerStatus");


  // Runs when the user chooses a file
  fileInput.addEventListener(
    "change",
    function () {

      const file =
        fileInput.files[0];

      // Make sure a file was selected
      if (!file) {
        return;
      }

      // Make sure it is an audio file
      if (
        !file.type.startsWith("audio/")
      ) {

        uploadStatus.textContent =
          "Please select an audio file.";

        return;
      }


      // Create a temporary browser URL
      // for the uploaded audio file
      const audioURL =
        URL.createObjectURL(file);


      // Give the audio player the song
      audioPlayer.src =
        audioURL;


      // Remove the file extension
      const cleanName =
        file.name.replace(
          /\.[^/.]+$/,
          ""
        );


      // Update the UI
      songName.textContent =
        cleanName;

      songType.textContent =
        file.type ||
        "Audio File";

      uploadStatus.textContent =
        file.name +
        " uploaded successfully.";

      playerStatus.textContent =
        "Ready to Play";

      playerStatus.classList.add(
        "ready"
      );

    }
  );


  // Update status when playing
  audioPlayer.addEventListener(
    "play",
    function () {

      playerStatus.textContent =
        "Playing";

    }
  );


  // Update status when paused
  audioPlayer.addEventListener(
    "pause",
    function () {

      if (!audioPlayer.ended) {

        playerStatus.textContent =
          "Paused";

      }

    }
  );


  // Update status when song finishes
  audioPlayer.addEventListener(
    "ended",
    function () {

      playerStatus.textContent =
        "Finished";

    }
  );

</script>

</body>
</html>