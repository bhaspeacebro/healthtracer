document.addEventListener("DOMContentLoaded", () => {
  const form = document.getElementById("healthForm");
  const modal = createModal(); // Create modal once DOM is ready
  document.body.appendChild(modal);

  form.addEventListener("submit", function (event) {
    event.preventDefault();

    const sleep = form.elements["sleep"].value;
    const steps = form.elements["steps"].value;
    const water = form.elements["water"].value;

    if (!sleep || !steps || !water) {
      showModal("❌ Missing Info", "Please fill in all fields before submitting.");
      shakeFields([form.elements["sleep"], form.elements["steps"], form.elements["water"]]);
    } else {
      console.log(`Logged: Sleep=${sleep}, Steps=${steps}, Water=${water}`);
      showModal("✅ Success", "Health data submitted! Thanks for logging.");
      updateSidebar(sleep, steps, water);
      form.reset();
    }
  });

  // 🧠 Shake fields with animation
  function shakeFields(fields) {
    fields.forEach(field => {
      if (!field.value) {
        field.style.borderColor = "#ff4d4d";
        field.classList.add("shake");
        setTimeout(() => field.classList.remove("shake"), 500);
      }
    });
  }

  // 🎯 Show modal popup
  function showModal(title, message) {
    modal.querySelector("h3").textContent = title;
    modal.querySelector("p").textContent = message;
    modal.classList.add("show");
    setTimeout(() => modal.classList.remove("show"), 3000);
  }

  // 🧩 Create modal element dynamically
  function createModal() {
    const modalDiv = document.createElement("div");
    modalDiv.className = "modal";
    modalDiv.innerHTML = `
      <h3></h3>
      <p></p>
    `;
    return modalDiv;
  }

  // 📊 Update sidebar preview
  function updateSidebar(sleep, steps, water) {
    const logList = document.getElementById("previewList");
    const entry = document.createElement("li");
    entry.innerHTML = `😴 ${sleep} hrs &nbsp; 👟 ${steps} steps &nbsp; 💧 ${water} ml`;
    logList.prepend(entry);
  }
});
