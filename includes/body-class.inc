<?php switch ($page->rootParent->id) {
  case "1010":
    $sectionClass = "campKulaqua-section";
    break;
  case "1011":
    $sectionClass = "kulaquaSummerCamp-section";
    break;
  case "1014":
    $sectionClass = "pineLake-section";
    break;
  case "1013":
    $sectionClass = "stillWaters-section";
    break;
  default:
    $sectionClass = "general-section";
}
?>

<body class="<?= $sectionClass ?>">